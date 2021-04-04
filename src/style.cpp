#include "style.h"

style::style()
{
	string normalFontWithPluses = normalFont;
	string accentFontWithPluses = accentFont;
	replace(normalFontWithPluses.begin(), normalFontWithPluses.end(), ' ', '+');
	replace(accentFontWithPluses.begin(), accentFontWithPluses.end(), ' ', '+');
	baseCSS = "@import url(\"https://fonts.googleapis.com/css2?family=" + normalFontWithPluses + "&family=" + accentFontWithPluses + "&display=swap\");body{overflow:hidden;font-size:2vw;font-family:\"" + normalFont + "\";height:100vh;margin:0;background-color:#000;color:#fff;display:flex;justify-content:center;align-items:center}h1:after{display:block;}";
}

string style::getEscapedMusicURL()
{
	string toReturn = musicURL;
	int pos;

	while ((pos = toReturn.find("\\")) != string::npos)
		toReturn.replace(pos, 1, "/");
	return toReturn;
}
