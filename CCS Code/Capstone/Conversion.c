
#include <std.h>
#include <log.h>

extern Int32 GD;

Int32 ConversionTable(char rx){
	if (rx == ' ') {return 0x1049;}	//using decimal
	else if (rx == '!'){return 5042;}
	else if (rx == '#'){return 9035;}
	else if (rx == '$'){return 13028;}
	else if (rx == '%'){return 17021;}
	else if (rx == '&'){return 21014;}
	else if(rx == '('){return 25007;}
	else if (rx == ')'){return 29000;}
	else if (rx == '*'){return 32993;}
	else if (rx == '+'){return 36986;}
	else if (rx == ','){return 40979;}
	else if (rx == '-'){return 44972;}
	else if (rx == '.'){return 48965;}
	else if (rx =='/'){return 52958;}
	else if (rx =='4'){return 72923;}
	else if (rx == '5'){return 76916;}
	else if (rx == '6'){return 80909;}
	else if (rx == '7'){return 84902;}
	else if (rx == '8'){return 88895;}
	else if (rx == '9'){return 92888;}
	else if (rx == ':'){return 96881;}
	else if (rx == ';'){return 100874;}
	else if (rx == '<'){return 104867;}
	else if (rx == '='){return 108860;}
	else if (rx == '>'){return 112853;}
	else if (rx == '?'){return 116846;}
	else if (rx == '@'){return 120839;}
	else if (rx =='A'){return 124832;}
	else if (rx == 'B'){return 128825;}
	else if (rx == 'C'){return 132818;}
	else if (rx == 'D'){return 136811;}
	else if (rx == 'E'){return 140804;}
	else if (rx == 'F'){return 144797;}
	else if (rx =='G'){return 148790;}
	else if (rx == 'H'){return 152783;}
	else if (rx == 'I'){return 156776;}
	else if (rx == 'J'){return 160769;}
	else if (rx == 'K'){return 164762;}
	else if (rx == 'L'){return 168755;}
	else if (rx == 'M'){return 172748;}
	else if (rx == 'N'){return 176741;}
	else if (rx == 'O'){return 180734;}
	else if (rx == 'P'){return 182833;}
	else if (rx == 'Q'){return 184727;}
	else if (rx == 'R'){return 188720;}
	else if (rx == 'S'){return 192713;}
	else if (rx == 'T'){return 196706;}
	else if (rx == 'U'){return 200699;}
	else if (rx =='V'){return 204692;}
	else if (rx == 'W'){return 208685;}
	else if (rx == 'X'){return 212678;}
	else if (rx == 'Y'){return 216671;}
	else if (rx == 'Z'){return 220664;}
	else if (rx == '['){return 224657;}
	else if (rx == ']'){return 228650;}
	else if (rx == '^'){return 232643;}
	else if (rx == '_'){return 236636;}
	else if (rx == '`'){return 240629;}
	else if (rx == 'a'){return 244622;}
	else if (rx == 'b'){return 248615;}
	else if (rx == 'c'){return 252608;}
	else if (rx == 'd'){return 256601;}
	else if (rx == 'e'){return 260594;}
	else if (rx == 'f'){return 264587;}
	else if (rx == 'g'){return 268580;}
	else if (rx == 'h'){return 272573;}
	else if (rx == 'i'){return 276566;}
	else if (rx == 'j'){return 280559;}
	else if (rx == 'k'){return 284552;}
	else if (rx == 'l'){return 288545;}
	else if (rx == 'm'){return 292538;}
	else if (rx == 'n'){return 296531;}
	else if (rx == 'o'){return 300524;}
	else if (rx == 'p'){return 304517;}
	else if (rx == 'q'){return 308510;}
	else if (rx == 'r'){return 312503;}
	else if (rx == 's'){return 316496;}
	else if (rx == 't'){return 320489;}
	else if (rx == 'u'){return 324482;}
	else if (rx == 'v'){return 328475;}
	else if (rx == 'w'){return 332468;}
	else if (rx == 'x'){return 336461;}
	else if (rx == 'y'){return 340454;}
	else if (rx == 'z'){return 344447;}
	else if (rx == '{'){return 348440;}
	else if (rx == '|'){return 360448;}		// next in chain is 352433
	// else if (rx == '}'){return 0x58000;}		SAVE FOR MUTE OFF
	//else if (rx == '~'){return ?;}			SAVE FOR MUTE ON

	else {return GD;}


}




