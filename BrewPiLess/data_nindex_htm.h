const char data_nindex_htm[] PROGMEM =
R"END(
<html>
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>BrewPiLess reporting for duty!</title>
<meta name="apple-mobile-web-app-title" content="BrewPiLess">
<meta name="apple-mobile-web-app-capable" content="yes">
<script src="http://cdnjs.cloudflare.com/ajax/libs/dygraph/1.1.1/dygraph-combined.js"></script>
<script type="text/javascript" src="bwf.js"></script>
<script>/*<![CDATA[*/var Q=function(a){return document.querySelector(a)};var BrewChart=function(b){this.cid=b;this.ctime=0;this.interval=60;this.numLine=4;this.lidx=0;this.celius=true;this.beerSet=NaN;this.auxTemp=NaN;this.gravity=null;this.sg=NaN;this.og=NaN};BrewChart.prototype.setCelius=function(a){this.celius=a;this.ylabel(STR.ChartLabel+"("+(a?"°C":"°F")+")")};BrewChart.prototype.incTime=function(){this.ctime+=this.interval};BrewChart.prototype.formatDate=function(h){var f=h.getHours();var e=h.getMinutes();var i=h.getSeconds();function g(a){return(a>9)?a:("0"+a)}return h.toLocaleDateString()+" "+g(f)+":"+g(e)+":"+g(i)};BrewChart.prototype.showLegend=function(f,e){var i=new Date(f);Q(".beer-chart-legend-time").innerHTML=this.formatDate(i);Q(".chart-legend-row.beerTemp .legend-value").innerHTML=this.tempFormat(this.chart.getValue(e,2));Q(".chart-legend-row.beerSet .legend-value").innerHTML=this.tempFormat(this.chart.getValue(e,1));Q(".chart-legend-row.fridgeTemp .legend-value").innerHTML=this.tempFormat(this.chart.getValue(e,3));Q(".chart-legend-row.fridgeSet .legend-value").innerHTML=this.tempFormat(this.chart.getValue(e,4));Q(".chart-legend-row.roomTemp .legend-value").innerHTML=this.tempFormat(this.chart.getValue(e,5));Q(".chart-legend-row.auxTemp .legend-value").innerHTML=this.tempFormat(this.chart.getValue(e,7));var h=this.chart.getValue(e,6);Q(".chart-legend-row.gravity .legend-value").innerHTML=(h!=null)?h.toFixed(3):"--";var j=parseInt(this.state[e]);if(!isNaN(j)){Q(".chart-legend-row.state .legend-label").innerHTML=STATES[j].text}};BrewChart.prototype.hideLegend=function(){var a=document.querySelectorAll(".legend-value");a.forEach(function(b){b.innerHTML="--"});Q(".beer-chart-legend-time").innerHTML=this.dateLabel;Q(".chart-legend-row.state .legend-label").innerHTML="state"};BrewChart.prototype.tempFormat=function(e){var c=parseFloat(e);if(isNaN(c)){return"--"}var b=this.celius?"°C":"°F";return parseFloat(c).toFixed(2)+b};BrewChart.prototype.initLegend=function(){Q(".chart-legend-row.beerTemp").style.color=BrewChart.Colors[1];Q(".beerTemp .toggle").style.backgroundColor=BrewChart.Colors[1];Q(".chart-legend-row.beerSet").style.color=BrewChart.Colors[0];Q(".beerSet .toggle").style.backgroundColor=BrewChart.Colors[0];Q(".chart-legend-row.fridgeTemp").style.color=BrewChart.Colors[2];Q(".fridgeTemp .toggle").style.backgroundColor=BrewChart.Colors[2];Q(".chart-legend-row.fridgeSet").style.color=BrewChart.Colors[3];Q(".fridgeSet .toggle").style.backgroundColor=BrewChart.Colors[3];Q(".chart-legend-row.roomTemp").style.color=BrewChart.Colors[4];Q(".roomTemp .toggle").style.backgroundColor=BrewChart.Colors[4];Q(".chart-legend-row.gravity").style.color=BrewChart.Colors[5];Q(".gravity .toggle").style.backgroundColor=BrewChart.Colors[5];Q(".chart-legend-row.auxTemp").style.color=BrewChart.Colors[6];Q(".auxTemp .toggle").style.backgroundColor=BrewChart.Colors[6];this.dateLabel=Q(".beer-chart-legend-time").innerHTML};BrewChart.prototype.toggleLine=function(b){this.shownlist[b]=!this.shownlist[b];if(this.shownlist[b]){Q("."+b+" .toggle").style.backgroundColor=Q(".chart-legend-row."+b).style.color;this.chart.setVisibility(this.chart.getPropertiesForSeries(b).column-1,true)}else{Q("."+b+" .toggle").style.backgroundColor="transparent";this.chart.setVisibility(this.chart.getPropertiesForSeries(b).column-1,false)}};BrewChart.prototype.createChart=function(){var a=this;a.initLegend();a.shownlist={beerTemp:true,beerSet:true,fridgeSet:true,fridgeTemp:true,roomTemp:true,gravity:true,auxTemp:true};var e=document.createElement("div");e.className="hide";document.body.appendChild(e);var b={labels:BrewChart.Labels,colors:BrewChart.Colors,connectSeparatedPoints:true,ylabel:"Temperature",y2label:"Gravity",series:{gravity:{axis:"y2",drawPoints:true,pointSize:2,highlightCircleSize:4}},axisLabelFontSize:12,animatedZooms:true,gridLineColor:"#ccc",gridLineWidth:"0.1px",labelsDiv:e,labelsDivStyles:{display:"none"},displayAnnotations:true,strokeWidth:1,axes:{y:{valueFormatter:function(c){return a.tempFormat(c)}},y2:{valueFormatter:function(c){return c.toFixed(3)},axisLabelFormatter:function(c){return c.toFixed(3).substring(1)}}},highlightCircleSize:2,highlightSeriesOpts:{strokeWidth:1.5,strokeBorderWidth:1,highlightCircleSize:5},highlightCallback:function(h,f,g,c){a.showLegend(f,c)},unhighlightCallback:function(c){a.hideLegend()}};a.chart=new Dygraph(document.getElementById(a.cid),a.data,b)};var STATES=[{name:"IDLE",text:"Idle"},{name:"STATE_OFF",text:"Off"},{name:"DOOR_OPEN",text:"Door Open",doorOpen:true},{name:"HEATING",text:"Heating"},{name:"COOLING",text:"Cooling"},{name:"WAITING_TO_COOL",text:"Waiting to Cool",waiting:true},{name:"WAITING_TO_HEAT",text:"Waiting to Heat",waiting:true},{name:"WAITING_FOR_PEAK_DETECT",text:"Waiting for Peak",waiting:true},{name:"COOLING_MIN_TIME",text:"Cooling Min Time",extending:true},{name:"HEATING_MIN_TIME",text:"Heating Min Time",extending:true}];BrewChart.Mode={b:"Beer Constant",f:"Fridge Constant",o:"Off",p:"Profile"};BrewChart.Colors=["rgb(240, 100, 100)","rgb(41,170,41)","rgb(89, 184, 255)","rgb(255, 161, 76)","#AAAAAA","rgb(153,0,153)","#f5e127"];BrewChart.Labels=["Time","beerSet","beerTemp","fridgeTemp","fridgeSet","roomTemp","gravity","auxTemp"];BrewChart.prototype.addMode=function(a){var b=String.fromCharCode(a);this.anno.push({series:"beerTemp",x:this.ctime*1000,shortText:b.toUpperCase(),text:BrewChart.Mode[b],attachAtBottom:true})};BrewChart.testData=function(b){if(b[0]!=255){return false}var c=b[1]&7;if(c>5){return false}return{sensor:c,f:b[1]&16}};BrewChart.prototype.addResume=function(b){this.ctime+=b;this.anno.push({series:"beerTemp",x:this.ctime*1000,shortText:"R",text:"Resume",attachAtBottom:true})};BrewChart.prototype.process=function(z){var y=false;var B=this;for(var o=0;o<z.length;){var x=z[o++];var u=z[o++];if(x==255){B.celius=(u&16)?false:true;var l=z[o++];l=l*256+z[o++];B.interval=l;B.starttime=(z[o]<<24)+(z[o+1]<<16)+(z[o+2]<<8)+z[o+3];B.ctime=B.starttime;o+=4;B.data=[];B.anno=[];B.state=[];B.cstate=0;y=true}else{if(x==244){B.addMode(u)}else{if(x==241){B.cstate=u}else{if(x==247){var s=z[o++];var r=z[o++];var A=(s&127)*256+r;B.beerSet=(A==32767)?NaN:(A/100)}else{if(x==248){var s=z[o++];var r=z[o++];var A=(s&127)*256+r;if(u){B.og=1+(A-1000)/1000}else{B.gravity=(A==32767)?NaN:(1+(A-1000)/1000);B.sg=B.gravity}}else{if(x==249){var s=z[o++];var r=z[o++];var A=(s&127)*256+r;B.auxTemp=(A==32767)?NaN:(A/100)}else{if(x==254){if(B.lidx){var q;for(q=B.lidx;q<B.numLine;q++){B.dataset.push(NaN)}B.data.push(B.dataset)}B.lidx=0;B.addResume(u)}else{if(x<128){if(B.lidx==0){var w=new Date(this.ctime*1000);var n=B.beerSet;B.dataset=[w,n];B.incTime()}var m=x*256+u;if(m==32767||m>12000){m=NaN}else{m=m/100}B.dataset.push(m);if(++B.lidx>=B.numLine){B.dataset.push(B.gravity);B.dataset.push(B.auxTemp);B.gravity=null;B.lidx=0;B.data.push(B.dataset);B.state.push(B.cstate)}}}}}}}}}}if(typeof B.chart=="undefined"){B.createChart()}else{B.chart.updateOptions({file:B.data})}B.chart.setAnnotations(B.anno);return y};var BrewPiSetting={valid:false,maxDegree:30,minDegree:0,tempUnit:"C"};var ControlChart={unit:"C",process:function(f){var h=this;h.data=[];if(typeof f=="undefined"){return}var e=new Date(f.s);h.unit=f.u;for(var g=0;g<f.t.length;g++){var j=new Date(e.getTime()+Math.round(f.t[g].d*86400)*1000);this.data.push([j,f.t[g].t])}},init:function(g,f){var h=this;h.process(f);var j=function(a){d=new Date(a);return(d.getMonth()+1)+"/"+d.getDate()};var i=function(a){return a.toFixed(1)+"&deg;"+h.unit};h.chart=new Dygraph(document.getElementById(g),h.data,{colors:["rgb(89, 184, 255)"],axisLabelFontSize:12,gridLineColor:"#ccc",gridLineWidth:"0.1px",labels:["Time","Temperature"],labelsDiv:document.getElementById(g+"-label"),legend:"always",labelsDivStyles:{textAlign:"right"},strokeWidth:1,axes:{y:{valueFormatter:i,pixelsPerLabel:20,axisLabelWidth:35},x:{axisLabelFormatter:j,valueFormatter:j,pixelsPerLabel:30,axisLabelWidth:40}},highlightCircleSize:2,highlightSeriesOpts:{strokeWidth:1.5,strokeBorderWidth:1,highlightCircleSize:5},})},update:function(a){if(a===false){return}this.process(a);this.chart.updateOptions({file:this.data})}};function formatDate(e){var k=e.getFullYear();var j=e.getMonth()+1;var i=e.getDate();var g=e.getHours();var c=e.getMinutes();var f=e.getSeconds();function b(a){return(a<10)?"0"+a:a}return b(j)+"/"+b(i)+"/"+k+" "+b(g)+":"+b(c)+":"+b(f)}var profileEditor={dirty:false,tempUnit:"C",C_startday_Id:"startdate",C_savebtn_Id:"savebtn",markdirty:function(a){this.dirty=a;document.getElementById(this.C_savebtn_Id).innerHTML=(a)?"Save*":"Save"},getStartDate:function(){return this.sd},setStartDate:function(a){},startDayChange:function(){var b=new Date(document.getElementById(this.C_startday_Id).value);if(isNaN(b.getTime())){document.getElementById(this.C_startday_Id).value=formatDate(this.sd)}else{this.sd=b;this.sortrow();this.markdirty(true)}},startnow:function(){var a=new Date();document.getElementById(this.C_startday_Id).value=formatDate(a);this.sd=a;this.sortrow();this.markdirty(true)},deleteRow:function(c){var b=document.getElementById("profile_t").getElementsByTagName("tr")[c];b.parentNode.removeChild(b);this.sortrow();this.markdirty(true)},showmenu:function(i,h){var g=h.rowIndex;i.preventDefault();var f=document.createElement("div");f.className="contextmenu";f.innerHTML="Delete!";f.style.top=(i.clientY-1)+"px";f.style.left=(i.clientX-1)+"px";f.onmouseout=function(){f.parentNode.removeChild(f)};var k=this;f.onclick=function(){f.parentNode.removeChild(f);k.deleteRow(g)};var j=document.getElementsByTagName("body")[0];j.appendChild(f)},dayChange:function(b){if(b.innerHTML==""||isNaN(b.innerHTML)){b.innerHTML=b.saved}this.sortrow();this.markdirty(true)},tempChange:function(b){if(b.innerHTML==""||isNaN(b.innerHTML)){b.innerHTML=b.saved}else{this.markdirty(true);ControlChart.update(this.getProfile())}},newrow:function(n,j,i){var e=this;var o=document.createElement("tr");var m=document.createElement("td");m.className="pday";m.innerHTML=(typeof n!=="undefined")?n:0;m.contentEditable=true;m.onblur=function(){e.dayChange(this)};m.onfocus=function(){this.saved=this.innerHTML};var l=document.createElement("td");l.className="ptemp";l.innerHTML=(typeof j!=="undefined")?j:20;l.contentEditable=true;l.onblur=function(){e.tempChange(this)};l.onfocus=function(){this.saved=this.innerHTML};var k=document.createElement("td");k.className="pdaystr";k.innerHTML=(i)?i:"";o.appendChild(m);o.appendChild(l);o.appendChild(k);o.oncontextmenu=function(a){e.showmenu(a,this);return false};return o},datestr:function(e){var c=new Date(this.sd.getTime()+Math.round(e*86400)*1000);return formatDate(c)},addRow:function(){var e=document.getElementById("profile_t").getElementsByTagName("tbody")[0];var c=e.getElementsByTagName("tr");var f=this.newrow();f.className=(c.length%2)?"odd":"even";e.appendChild(f);this.markdirty(true)},init:function(e,g){this.sd=g;document.getElementById(this.C_startday_Id).value=formatDate(g);var b=document.getElementById("profile_t").getElementsByTagName("tbody")[0];for(var c=0;c<e.length;c++){var f=this.newrow(e[c].d,e[c].t,this.datestr(e[c].d));f.className=(c%2)?"odd":"even";b.appendChild(f)}},sortrow:function(){var m=document.getElementById("profile_t").getElementsByTagName("tbody")[0];var l=m.getElementsByTagName("tr");var k=Array.prototype.slice.call(l);k.sort(function(f,e){var h=parseFloat(f.querySelector("td.pday").innerHTML);var g=parseFloat(e.querySelector("td.pday").innerHTML);if(isNaN(h)||isNaN(g)||(h===g)){return 0}else{return h-g}});for(var b=0;b<k.length;b++){var c=k[b];var a=c.querySelector("td.pday").innerHTML;c.querySelector("td.pdaystr").innerHTML=this.datestr(parseFloat(a));c.className=(b%2)?"odd":"even";c.parentNode.removeChild(c);m.appendChild(c)}ControlChart.update(this.getProfile())},clear:function(){var f=document.getElementById("profile_t").getElementsByTagName("tbody")[0];var e=f.getElementsByTagName("tr");var j=e.length;for(var g=e.length-1;g>=0;g--){var h=e[g];h.parentNode.removeChild(h)}this.markdirty(true)},getProfile:function(){var r=document.getElementById("profile_t").getElementsByTagName("tbody")[0];var q=r.getElementsByTagName("tr");var p=q.length;var o=0;var n=[];for(var j=0;j<q.length;j++){var m=q[j];var l=parseFloat(m.querySelector("td.pday").innerHTML);var k=parseFloat(m.querySelector("td.ptemp").innerHTML);if(isNaN(l)||isNaN(k)){return false}if(k>BrewPiSetting.maxDegree||k<BrewPiSetting.minDegree){return false}if(j==0){if(l!=0){return false}}else{if(o==l){return false}}o=l;n.push({d:l,t:k})}var t=this.sd.toISOString();return{s:t,u:this.tempUnit,t:n}},initProfile:function(c){var b=new Date(c.s);this.tempUnit=c.u;profileEditor.init(c.t,b)},setTempUnit:function(g){if(g==this.tempUnit){return}this.tempUnit=g;var f=document.getElementById("profile_t").getElementsByTagName("tbody")[0];var e=f.getElementsByTagName("tr");for(var h=0;h<e.length;h++){var k=e[h].querySelector("td.ptemp");var j=parseFloat(k.innerHTML);k.innerHTML=(g=="C")?F2C(j):C2F(j)}}};var modekeeper={initiated:false,modes:["profile","beer","fridge","off"],cmode:0,dselect:function(b){var e=document.getElementById(b+"-m");var c=document.getElementById(b+"-m").className.replace(/\snav-selected/,"");e.className=c;document.getElementById(b+"-s").style.display="none"},select:function(a){document.getElementById(a+"-m").className+=" nav-selected";document.getElementById(a+"-s").style.display="block"},init:function(){var c=this;if(c.initiated){return}c.initiated=true;for(var e=0;e<4;e++){var a=c.modes[e];document.getElementById(a+"-s").style.display="none";document.getElementById(a+"-m").onclick=function(){var b=this.id.replace(/-m/,"");c.dselect(c.cmode);c.select(b);c.cmode=b}}c.cmode="profile";c.select(c.cmode)},apply:function(){if(!BrewPiSetting.valid){alert("Not connected to controller.");return}if((this.cmode=="beer")||(this.cmode=="fridge")){var a=document.getElementById(this.cmode+"-t").value;if(a==""||isNaN(a)||(a>BrewPiSetting.maxDegree||a<BrewPiSetting.minDegree)){alert("Invalid Temperature:"+a);return}if(this.cmode=="beer"){console.log("j{mode:b, beerSet:"+a+"}");BWF.send("j{mode:b, beerSet:"+a+"}")}else{console.log("j{mode:f, fridgeSet:"+a+"}");BWF.send("j{mode:f, fridgeSet:"+a+"}")}}else{if(this.cmode=="off"){console.log("j{mode:o}");BWF.send("j{mode:o}")}else{if(profileEditor.dirty){alert("save the profile first before apply");return}console.log("j{mode:p}");BWF.send("j{mode:p}")}}}};function saveprofile(){console.log("save");var c=profileEditor.getProfile();if(c===false){alert("invalid value. check again");return}var b=JSON.stringify(c);console.log("result="+b);BWF.save(BWF.BrewProfile,b,function(){profileEditor.markdirty(false);alert("Done.")},function(a){alert("save failed:"+a)})}function C2F(a){return Math.round((a*1.8+32)*10)/10}function F2C(a){return Math.round((a-32)/1.8*10)/10}function updateTempUnit(c){var b=document.getElementsByClassName("t_unit");for(var e=0;e<b.length;e++){b[e].innerHTML=c}}function openDlgLoading(){document.getElementById("dlg_loading").style.display="block"}function closeDlgLoading(){document.getElementById("dlg_loading").style.display="none"}function onload(){modekeeper.init();openDlgLoading();function a(){var c=true;function e(){if(!c){return}c=false;closeDlgLoading()}invoke({url:"/tcc",m:"GET",fail:function(b){console.log("error connect to BrwePiLess!");e()},success:function(g){var f=JSON.parse(g);var b={valid:true,minDegree:f.tempSetMin,maxDegree:f.tempSetMax,tempUnit:f.tempFormat};if(b.tempUnit!=BrewPiSetting.tempUnit){updateTempUnit(b.tempUnit);profileEditor.setTempUnit(b.tempUnit)}BrewPiSetting=b;e()}})}BWF.load(BWF.BrewProfile,function(c){var b=JSON.parse(c);updateTempUnit(b.u);BrewPiSetting.tempUnit=b.u;profileEditor.initProfile(b);ControlChart.init("tc_chart",b);a()},function(b){profileEditor.init([],new Date());ControlChart.init("tc_chart");a()})}function s_ajax(a){var e=new XMLHttpRequest();e.onreadystatechange=function(){if(e.readyState==4){if(e.status==200){a.success(e.responseText)}else{e.onerror(e.status)}}};e.ontimeout=function(){if(typeof a.timeout!="undefined"){a.timeout()}else{e.onerror(-1)}},e.onerror=function(b){if(typeof a.fail!="undefined"){a.fail(b)}};e.open(a.m,a.url,true);if(typeof a.data!="undefined"){e.setRequestHeader("Content-Type",(typeof a.mime!="undefined")?a.mime:"application/x-www-form-urlencoded");e.send(a.data)}else{e.send()}}function getLogName(){s_ajax({url:"loglist.php",m:"GET",success:function(b){var a=JSON.parse(b);if(a.rec){Q("#recording").innerHTML=a.log}else{Q("#recording").innerHTML=""}},fail:function(a){alert("failed:"+a)}})}var BChart={offset:0,url:"chart.php",toggle:function(b){this.chart.toggleLine(b)},reqdata:function(){var a=this;var e="offset="+a.offset;if(typeof a.startOff!="undefined"&&a.startOff!==null){e=e+"&index="+a.startOff}var b=new XMLHttpRequest();b.open("GET",a.url+"?"+e);b.responseType="arraybuffer";b.onload=function(g){if(this.status==404){console.log("Error getting log data");return}var f=new Uint8Array(this.response);if(f.length==0){console.log("zero content");if(a.timer){clearInterval(a.timer)}a.timer=null;setTimeout(function(){a.reqdata()},3000);return}var c=a.chart.process(f);if(c){a.offset=f.length;a.startOff=b.getResponseHeader("LogOffset");getLogName();console.log("new chart, offset="+a.startOff)}else{a.offset+=f.length}if(!isNaN(a.chart.og)){updateOriginGravity(a.chart.og)}if(!isNaN(a.chart.sg)){updateGravity(a.chart.sg)}if(a.timer==null){a.settimer()}};b.onerror=function(){console.log("error getting data.");setTimeout(function(){a.reqdata()},10000)};b.send()},settimer:function(){var a=this;a.timer=setInterval(function(){a.reqdata()},a.chart.interval*1000)},init:function(b){this.chart=new BrewChart(b)},timer:null,start:function(){if(this.running){return}this.running=true;this.offset=0;this.reqdata()},reqnow:function(){var a=this;if(a.timer){clearInterval(a.timer)}a.timer=null;a.reqdata()}};function setLcdText(e,c){var f=document.getElementById(e);f.innerHTML=c}function communicationError(){setLcdText("lcd-line-0","Failed to");setLcdText("lcd-line-1","connect to");setLcdText("lcd-line-2","Server");setLcdText("lcd-line-3","")}function controllerError(){setLcdText("lcd-line-0","Controller not");setLcdText("lcd-line-1","updating data");setLcdText("lcd-line-2","...");setLcdText("lcd-line-3","")}function init(){var a=true;BWF.init({error:function(b){console.log("error");communicationError()},handlers:{L:function(b){a=true;for(var c=0;c<4;c++){setLcdText("lcd-line-"+c,b[c])}},V:function(b){console.log("forced reload chart");BChart.reqnow()}}});setInterval(function(){if(!a){controllerError()}BWF.send("l");a=false},5000);BWF.send("l");BChart.init("div_g");BChart.start();onload()}var BrewMath={abv:function(e,c){return((76.08*(e-c)/(1.775-e))*(c/0.794)).toFixed(1)},att:function(e,c){return Math.round((e-c)/(e-1)*100)}};function updateGravity(b){if(typeof window.sg!="undefined"&&window.sg==b){return}window.sg=b;Q("#gravity-sg").innerHTML=b.toFixed(3);if(typeof window.og!="undefined"){Q("#gravity-att").innerHTML=BrewMath.att(window.og,b);Q("#gravity-abv").innerHTML=BrewMath.abv(window.og,b)}}function updateOriginGravity(b){if(typeof window.og!="undefined"&&window.og==b){return}window.og=b;Q("#gravity-og").innerHTML=b.toFixed(3);if(typeof window.sg!="undefined"){updateGravity(window.sg)}}function showgravitydlg(b){Q("#dlg_addgravity .msg").innerHTML=b;Q("#dlg_addgravity").style.display="block"}function dismissgravity(){Q("#dlg_addgravity").style.display="none"}function inputgravity(){dismissgravity();openDlgLoading();var e=parseFloat(Q("#dlg_addgravity input").value);if(window.isog){updateOriginGravity(e)}else{updateGravity(e)}var c={name:"webjs",gravity:e};if(window.isog){c.og=1}s_ajax({url:"gravity",m:"POST",mime:"application/json",data:JSON.stringify(c),success:function(a){closeDlgLoading()},fail:function(a){alert("failed:"+a);closeDlgLoading()}})}function gravity(){window.isog=false;showgravitydlg("Add gravity Record:")}function origingravity(){window.isog=true;showgravitydlg("Set Original Gravity:")};/*]]>*/</script>
<style>.lcddisplay{width:280px;height:90px;float:left;margin:5px;background:#000;background:-moz-linear-gradient(top,#000000 2%,#2b2b2b 11%,#212121 54%,#212121 92%,#000000 100%);background:-webkit-gradient(linear,left top,left bottom,color-stop(2%,#000000),color-stop(11%,#2b2b2b),color-stop(54%,#212121),color-stop(92%,#212121),color-stop(100%,#000000));background:-webkit-linear-gradient(top,#000000 2%,#2b2b2b 11%,#212121 54%,#212121 92%,#000000 100%);background:-o-linear-gradient(top,#000000 2%,#2b2b2b 11%,#212121 54%,#212121 92%,#000000 100%);background:-ms-linear-gradient(top,#000000 2%,#2b2b2b 11%,#212121 54%,#212121 92%,#000000 100%);filter:progid:DXImageTransform.Microsoft.gradient(startColorstr='#000000',endColorstr='#000000',GradientType=0);background:linear-gradient(top,#000000 2%,#2b2b2b 11%,#212121 54%,#212121 92%,#000000 100%);-webkit-box-shadow:inset 1px 1px 5px #333;-moz-box-shadow:inset 1px 1px 5px #333;box-shadow:inset 1px 1px 5px #333;border:2px solid #333;-webkit-border-radius:2px;-moz-border-radius:2px;border-radius:2px}.lcddisplay .lcd-text{float:left;margin:5px 16px}.lcd-line{float:left;clear:left;font-size:16px;font-weight:normal;font-style:normal;font-family:"Courier New",Courier,monospace;color:#ff0;white-space:pre}.chart-legend-row .toggle{width:8px;height:8px;border-radius:5px;float:left;margin:2px 0 0 0;cursor:pointer;border:1px solid}.chart-legend{font-family:Lucida Grande,Lucida Sans,Arial,sans-serif;font-size:11px;margin:10px 0 0 0;border:solid 1px #777;border-radius:5px;float:right;width:155px}.chart-legend-row{padding:8px 5px 8px 5px}.legend-label{float:left;padding:0 5px 0 5px;cursor:pointer}.legend-value{float:right}.chart-legend-row.time{background-color:#def}#div_lb{display:none}#div_g{float:left;width:800px;height:390px}#chart-container{width:965px;height:410px;padding:5px 5px 5px 5px}.hide{display:none}.frame{border-radius:5px;margin:5px 5px 5px 5px;border:solid 1px #304d75;width:975px}#top-frame{height:520px}#bottom-frame{height:380px}#topbar{width:965px;height:108px;background-color:#5c9ccc;padding:5px 5px 5px 5px}#menu{float:right}#banner{font-size:18pt;float:left;color:white;font-family:fantasy;margin-top:16px;margin-left:16px}#recording{color:lightblue;font-size:18px}#top-frame button{float:right;width:200px;margin-top:3px}.navbar{margin:0;padding:.2em .2em 0;border:1px solid #4297d7;background:#5c9ccc;color:#fff;height:3.8em;display:block;position:relative}#set-mode-text{margin-left:2px;float:left;margin:.2em}.navitem{background:#dfeffc;font-weight:bold;color:#2e6e9e;margin:.2em .2em 0 0;padding:.5em;border-top-right-radius:5px;border-top-left-radius:5px}.nav-selected{background:#fff;font-weight:bold;color:#e17009;margin:.2em .2em 0 0;padding:.5em .5em .6em .5em}.navitems{display:block;margin-top:2em}#apply{background:#dfeffc;font-weight:bold;color:#2e6e9e;margin:.2em .1em 0 0;padding:.5em}#containter{margin:.5em;width:965px}.profileTable td,th{padding:3px;text-align:center}.profileTable tbody TR.odd{background:#f7f7f7}.profileTable tbody TR.even{width:100%}.profileTable TH{border:1px solid #4297d7;background:#5c9ccc;color:#fff;font-weight:bold}table.profileTable{width:100%}#bottom-frame button{color:#1d5987;background:#dfeffc;font-weight:bold;border-radius:5px}#addbutton{float:right;width:36%;margin:5px 1% 5px 1%}.contextmenu{display:block;position:absolute;background:#D00;color:#fff;font-weight:bold;padding:.5em}#header{width:968px}#clearbtn{width:48%}#savebtn{width:48%}.modal{display:none;position:fixed;z-index:100;padding-top:100px;left:0;top:0;width:100%;height:100%;overflow:auto;background-color:#000;background-color:rgba(0,0,0,0.4)}.modal-content{background-color:#fefefe;margin:auto;padding:10px;border:1px solid #888;width:320px;height:100px;border-radius:8px}#dlg_addgravity button{float:right;width:56px;margin-top:2px}#modekeeper-apply{margin-top:0}#profile-edit{float:left;margin:6px;width:420px}#tc_chart{width:430px;height:280px;float:right;margin:6px}#gravity-pane table{width:120px;float:right;border:1px solid white;border-radius:5px;margin-right:10px;color:cyan;font-size:12px}</style>
</head>
<body onload=init()>
<div class="frame" id="top-frame">
<div id="topbar">
<div id="lcd" class="lcddisplay"><span class="lcd-text">
<span class="lcd-line" id="lcd-line-0">Live LCD waiting</span>
<span class="lcd-line" id="lcd-line-1">for update from</span>
<span class="lcd-line" id="lcd-line-2">script...</span>
<span class="lcd-line" id="lcd-line-3"></span></p><p>
</div>
<div id="banner">BrewPiLess v1.2.6p1
<div id="recording"></div>
</div>
<div id="menu">
<button onclick="window.open('/log')">Data Logging</button>
<br>
<button onclick="window.open('/setup.htm')">Device Setup</button>
<br>
<button onclick="window.open('/config')">System Config</button>
<br>
</div>
<div id="gravity-pane">
<table>
<tr><th>OG:</th><td> <span id="gravity-og" onclick="origingravity()">--</span><td></tr>
<tr><th>SG:</th><td> <span id="gravity-sg" onclick="gravity()">--</span><td></tr>
<tr><th>ATT:</th><td> <span id="gravity-att"> --</span>%<td></tr>
<tr><th>ABV:</th><td> <span id="gravity-abv"> --</span>%<td></tr>
</table>
</div>
</div>
<div id="chart-container">
<div id="div_g"></div>
<div id="chart-legend" class="chart-legend">
<div class="chart-legend-row time">
<div class="beer-chart-legend-time">Date/Time</div>
</div>
<div class="chart-legend-row beerTemp">
<div class="toggle beerTemp" onclick="BChart.toggle('beerTemp')"></div>
<div class="legend-label" onclick="BChart.toggle('beerTemp')">Beer Temp</div>
<div class="legend-value">--</div>
<br>
</div>
<div class="chart-legend-row beerSet">
<div class="toggle beerSet" onclick="BChart.toggle('beerSet')"></div>
<div class="legend-label" onclick="BChart.toggle('beerSet')">Beer Set</div>
<div class="legend-value">--</div>
<br>
</div>
<div class="chart-legend-row fridgeTemp">
<div class="toggle beerSet" onclick="BChart.toggle('fridgeTemp')"></div>
<div class="legend-label" onclick="BChart.toggle('fridgeTemp')">Fridge Temp</div>
<div class="legend-value">--</div>
<br>
</div>
<div class="chart-legend-row fridgeSet">
<div class="toggle beerSet" onclick="BChart.toggle('fridgeSet')"></div>
<div class="legend-label" onclick="BChart.toggle('fridgeSet')">Fridge Set</div>
<div class="legend-value">--</div>
<br>
</div>
<div class="chart-legend-row roomTemp">
<div class="toggle beerSet" onclick="BChart.toggle('roomTemp')"></div>
<div class="legend-label" onclick="BChart.toggle('roomTemp')">Room Temp</div>
<div class="legend-value">--</div>
<br>
</div>
<div class="chart-legend-row gravity">
<div class="toggle gravity" onclick="BChart.toggle('gravity')"></div>
<div class="legend-label" onclick="BChart.toggle('gravity')">Gravity</div>
<div class="legend-value">--</div>
<br>
</div>
<div class="chart-legend-row auxTemp">
<div class="toggle gravity" onclick="BChart.toggle('auxTemp')"></div>
<div class="legend-label" onclick="BChart.toggle('auxTemp')">Aux Temp</div>
<div class="legend-value">--</div>
<br>
</div>
<div class="chart-legend-row state">
<div class="legend-label">state</div>
<br>
</div>
</div>
</div>
</div>
<div class="frame" id="bottom-frame">
<div class="navbar" id="header">
<div id="set-mode-text">Set temperature mode:</div>
<div class="navitems">
<span class="navitem" id="profile-m">Beer profile</span>
<span class="navitem" id="beer-m">Beer Const.</span>
<span class="navitem" id="fridge-m">Fridge Const.</span>
<span class="navitem" id="off-m">Off</span>
<button id="modekeeper-apply" onclick="modekeeper.apply()">Apply</button>
</div>
</div>
<div id="containter">
<div id="profile-s" class="detail">
<div id="profile-edit">
<div>
<div><span>Start Date:</span><input type="text" size="40" id="startdate" onchange="profileEditor.startDayChange()">
<button id="setnow" onclick=profileEditor.startnow()>Now</button></div>
<button id="addbutton" onclick="profileEditor.addRow()">Add</button>
</div>
<table class="profileTable" id="profile_t">
<thead><tr><th>Day</th><th>Temperature(&deg;<span class="t_unit">C</span>)</th><th>Date and Time</th></tr></thead>
<tbody></tbody>
</table>
<div><button id="clearbtn" onclick="profileEditor.clear()">Clear</button><button id="savebtn" onclick="saveprofile()">Save</button></div>
</div>
<div id="tc_chart"></div>
</div>
<div id="beer-s" class="detail">
Set Beer temp:
<input type="text" size="6" id="beer-t"></input>&deg;<span class="t_unit">C</span>
</div>
<div id="fridge-s" class="detail">
Set Fridge temp:
<input type="text" size="6" id="fridge-t"></input>&deg;<span class="t_unit">C</span>
</div>
<div id="off-s" class="detail">Turning temperature controll Off.</div>
</div>
<div id="dlg_loading" class="modal">
<div class="modal-content">
<p>Communicating with BrewPiLess controller..</p>
</div>
</div>
<div id="dlg_addgravity" class="modal">
<div class="modal-content">
<p><span class="msg"></span><input type="text" size="6" value="1.0">
<button onclick="dismissgravity()">Cancel</button>
<button onclick="inputgravity()">OK</button>
</p>
</div>
</div>
</div>
</body>
</html>
)END";



































































































































































