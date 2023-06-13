#include <iostream> 
#include <string> 

class SeasonsBase {
public:
    virtual ~SeasonsBase() = default;
    virtual std::string Change() = 0;
};

class Seasons : public SeasonsBase {
public:
    std::string Change() override {
        switch (current_season_) {
        case SeasonsEnum::spring:
            current_season_ = SeasonsEnum::summer;
            return "Spring -> Summer";
        case SeasonsEnum::summer:
            current_season_ = SeasonsEnum::fall;
            return "Summer -> Winter";
        case SeasonsEnum::fall:
            current_season_ = SeasonsEnum::winter;
            return "fall -> Winter";
        case SeasonsEnum::winter:
            current_season_ = SeasonsEnum::spring;
            return "Winter -> Spring";
        default:
            return "Invalid season";
        }
    }

private:
    enum class SeasonsEnum { spring, summer, fall, winter };
    SeasonsEnum current_season_ = SeasonsEnum::spring;
};

class ReverseSeasons : public SeasonsBase {
public:
    std::string Change() override {
        switch (current_season_) {
        case SeasonsEnum::spring:
            current_season_ = SeasonsEnum::winter;
            return "Spring <- Winter";
        case SeasonsEnum::summer:
            current_season_ = SeasonsEnum::spring;
            return "Summer <- Spring";
        case SeasonsEnum::autumn:
            current_season_ = SeasonsEnum::summer;
            return "Autumn <- Summer";
        case SeasonsEnum::winter:
            current_season_ = SeasonsEnum::autumn;
            return "Winter <- Autumn";
        default:
            return "Invalid season";
        }
    }

private:
    enum class SeasonsEnum { spring, summer, autumn, winter };
    SeasonsEnum current_season_ = SeasonsEnum::spring;
};

int main() {
    SeasonsBase* seasons = new ReverseSeasons;
    std::cout << seasons->Change() << std::endl;
    std::cout << seasons->Change() << std::endl;
    std::cout << seasons->Change() << std::endl;
    std::cout << seasons->Change() << std::endl;

    delete seasons;
    return 0;
}