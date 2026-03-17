const fs = require('fs');
const { PDFDocument, rgb, StandardFonts } = require('pdf-lib');

async function addFooter() {
    const inPath = 'NoiDungOnTap.pdf';
    const doc1Path = 'Doc1.pdf';
    const outPath = 'NoiDungOnTapHSG9_TPHCM.pdf';

    // 1. Load the main PDF and the cover PDF (Doc1.pdf)
    const pdfBytes = fs.readFileSync(inPath);
    const doc = await PDFDocument.load(pdfBytes);

    let doc1PageCount = 0;
    if (fs.existsSync(doc1Path)) {
        const doc1Bytes = fs.readFileSync(doc1Path);
        const doc1 = await PDFDocument.load(doc1Bytes);
        const doc1Pages = await doc.copyPages(doc1, doc1.getPageIndices());
        doc1PageCount = doc1Pages.length;
        
        // Prepend all pages from doc1.pdf to the start
        for (let i = 0; i < doc1PageCount; i++) {
            doc.insertPage(i, doc1Pages[i]);
        }
    }

    // 2. Setup fonts and get the new total page count
    const font = await doc.embedFont(StandardFonts.Helvetica);
    const pages = doc.getPages();
    const tot = pages.length;

    // 3. Loop through physical pages starting from PAGE 2 (index 1)
    // The number shown (cur) will also start at 2 (cur = i + 1).
    for (let i = 1; i < pages.length; i++) {
        const p = pages[i];
        const { width, height } = p.getSize();
        
        // Page numbering matches physical index + 1
        const cur = i + 1;
        const txt = `${cur} / ${tot}`;

        // Center the text horizontally
        const txtW = font.widthOfTextAtSize(txt, 9);
        const xPos = (width / 2) - (txtW / 2);
        
        p.drawText(txt, {
            x: xPos,
            y: 20,
            size: 9,
            font: font,
            color: rgb(0, 0, 0),
        });
    }

    // 4. Save the final output
    const outBytes = await doc.save();
    fs.writeFileSync(outPath, outBytes);
    console.log(`PDF updated successfully. Total pages: ${tot}. Prepended: ${doc1PageCount}.`);
}

addFooter();