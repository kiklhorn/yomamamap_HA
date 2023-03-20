

Import file into Node-RED

returned format: "TMEP compatible teploty JSON object" - http://homeassistant:1880/endpoint/volby
{
id: cislo LED (1..77),
h: hodnota (cislo kandidata nebo strany),
pct: procento sectenych hlasu (0..100)
}

call examples: 

http://homeassistant:1880/endpoint/volby?buff=true&typ=prezident&kolo=1&rok=2023 (buffered, prezidentske volby 2023, 1.kolo)
http://homeassistant:1880/endpoint/volby?buff=true&typ=pscr&rok=2021 (buffered, volby do PS, rok 2021) 

volby-flows-memory-usage.json - corrected URLs and debug part added

Non std nodes: (manage palette - install)  

https://flows.nodered.org/node/node-red-contrib-linux-memory

https://flows.nodered.org/node/node-red-contrib-device-stats (Not working correctly on my device)

