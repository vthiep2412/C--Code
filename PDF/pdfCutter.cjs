const { PDFDocument } = require('pdf-lib')
const fs = require('fs')
const readline = require('readline')
const path = require('path')

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
})

const ask = (q) => new Promise((res) => rl.question(q, res))

async function cutPdf() {
    const st = parseInt(await ask('Enter first page number: '))
    const en = parseInt(await ask('Enter second page number: '))
    const pth = await ask('Enter PDF file path: ').then(p => p.trim().replace(/^"|"$/g, ''))

    try {
        const bytes = fs.readFileSync(pth)
        const src = await PDFDocument.load(bytes)
        const dst = await PDFDocument.create()
        const total = src.getPageCount()

        if (st > en || st < 1 || en > total) {
            console.log('Invalid range')
            rl.close()
            return
        }

        const idxs = []
        for (let i = st - 1; i < en; i++) idxs.push(i)

        const pages = await dst.copyPages(src, idxs)
        pages.forEach((p) => dst.addPage(p))

        const outBytes = await dst.save()
        
        const dir = path.dirname(pth)
        const base = path.basename(pth, path.extname(pth))
        const outName = path.join(dir, `${base}_${st}-${en}.pdf`)

        fs.writeFileSync(outName, outBytes)
        console.log(`Successfully created: ${outName}`)
    } catch (err) {
        console.error('Error:', err.message)
    }
    rl.close()
}

cutPdf()