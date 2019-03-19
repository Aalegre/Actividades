#pragma once


struct Date {
	unsigned int day = 0;
	unsigned int month = 0;
	unsigned int year = 0;
	Date() {}
	Date(unsigned int day_, unsigned int month_, unsigned int year_) {
		day = day_; month = month_; year = year_;
	}
	//std::string print() {
	//	return std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
	//}
};

char letrasDNI[] = { 'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E' };
std::vector<std::string> nombres = { "Gertrudiz","Pancracia","Anacleto","Hipolito","Eustaquio","Fulgencia" };
struct Persona {
	std::string nombre = "";
	std::string apellido1 = "";
	std::string apellido2 = "";
	unsigned int nDNI = 47988121;
	char letraDNI = ' ';
	Date nacimiento;


	char getLetraDNI(unsigned int nDNI_) {
		return letrasDNI[nDNI_ % 23];
	}
	Persona() {
		nombre = nombres[rand() % nombres.size()];
		nDNI = rand() % 89999999 + 10000000;
		letraDNI = getLetraDNI(nDNI);
		nacimiento = Date(rand() % 30 + 1, rand() % 11 + 1, rand() % 100 + 1919);
	};
	Persona(std::string nombre_, unsigned int nDNI_, Date nacimiento_) {
		nombre = nombre_; nDNI = nDNI_; letraDNI = getLetraDNI(nDNI_); nacimiento = nacimiento_;
	}
	Persona(std::string nombre_, std::string apellido1_, std::string apellido2_, unsigned int nDNI_, Date nacimiento_) {
		nombre = nombre_; apellido1 = apellido1_; apellido2 = apellido2_; nDNI = nDNI_; letraDNI = getLetraDNI(nDNI_); nacimiento = nacimiento_;
	}
};