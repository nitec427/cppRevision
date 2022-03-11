#include <iostream>
#include <string>
#define LOG(x) std::cout << x << std::endl;
#define add_log(mes) << mes <<;
class Log { 
public:
	enum Level {
		LevelError = 0, LevelWarning, LevelInfo
	};
private:
	Level log_level = LevelInfo;
public:
	void setLevel(Level level) {
		log_level = level;
	}
	void Error(const char* message) {
		if (log_level >= LevelError) {
			std::cout << "ERROR: " << message << std::endl;
		}
	}
	void Warn(const char* message) {
		if (log_level >= LevelWarning) {
			std::cout << "[WARNING]: " << message << std::endl;
		}
	}

	void Info(const char* message) {
		if (log_level >= LevelInfo) {
			std::cout << "[INFO]: " << message << std::endl;
		}
	}
};

int main() {
	Log log;
	log.setLevel(Log::LevelInfo);
	log.Warn("This is a warning");
	std::cin.get();
}