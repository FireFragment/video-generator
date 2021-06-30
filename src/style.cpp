#include "style.h"

style::style()
{
	string normalFontWithPluses = normalFont;
	replace(normalFontWithPluses.begin(), normalFontWithPluses.end(), ' ', '+');
	baseCSS = "@import url(\"https://fonts.googleapis.com/css2?family=" + normalFontWithPluses + "&display=swap\");body{overflow:hidden;font-size:2vw;font-family:\"" + normalFont + "\";height:100vh;margin:0;background-color:#000;color:#fff;display:flex;justify-content:center;align-items:center}div{position:absolute;}";
}

string style::getEscapedMusicURL()
{
	string toReturn = musicURL;
	int pos;

	while ((pos = toReturn.find("\\")) != string::npos)
		toReturn.replace(pos, 1, "/");
	return toReturn;
}
