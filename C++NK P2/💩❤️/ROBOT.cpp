#include<bits/stdc++.h>
using namespace std;
typedef long long 🗿; typedef pair<🗿,🗿> 👫; typedef int 🎪; typedef void 😋; typedef bool 💩;
#define 🚀 main
#define 📥 cin
#define 📤 cout
#define 🔙 return
#define 🤔 if
#define 👺 else
#define 🥨 for
#define 🕹️ switch
#define 🎯 case
#define 🖥️ ios_base::sync_with_stdio(0);cin.tie(0);
#define 👻 first
#define 💀 second
#define 🍦 true
#define 🥀 false
#define 🐔 continue
#define 🤏 freopen
#define 👈 stdin
#define 👍 stdout
👫 📍, 🔜;
🗿 🗺️ = -1;
😋 🏎️(🗿 🧊, 🗿 🌡️, 🗿 🧊1, 🗿 🌡️1){
    🤔(🧊1>🧊) 🗺️ = 1;
    👺 🤔(🌡️1>🌡️) 🗺️ = 0;
    👺 🤔(🌡️1<🌡️) 🗺️ = 2;
    👺 🗺️ = 3;
}👫 🔮(🗿 🧊, 🗿 🌡️){
    🕹️(🗺️){
        🎯 0: 🔙 {🧊+1,🌡️};
        🎯 1: 🔙 {🧊,🌡️-1};
        🎯 2: 🔙 {🧊-1,🌡️};
        🎯 3: 🔙 {🧊, 🌡️+1};
    } 🔙{};
}🎪 🚀(){ 🖥️
    🤏("ROBOT.inp","r",👈);
    🤏("ROBOT.out","w",👍);
    🗿 🔢,🅰️,🅱️,🏆=0;
    💩 🤮 = 🍦, 🤨 = 🍦;
    📥 >> 🔢;
    🥨(🎪 🤡=0; 🤡<🔢; 🤡++){
        📥 >> 🅰️ >> 🅱️;
        🤔(🤮){
            📍 = {🅰️,🅱️};
            🤮 = 🥀;
            🐔;
        } 👺 🤔(🤨){
            🏎️(📍.👻, 📍.💀, 🅰️, 🅱️);
            🔜 = 🔮(🅰️, 🅱️);
            📍 = {🅰️, 🅱️};
            🤨 = 🥀;
            🐔;
        }
        🏎️(📍.👻, 📍.💀, 🅰️, 🅱️);
        🤔(🅰️ == 🔜.👻 and 🅱️ == 🔜.💀) 🏆++;
        🔜 = 🔮(🅰️, 🅱️);
        📍 = {🅰️, 🅱️};
    }
    📤 << 🏆;
    🔙 0;
}