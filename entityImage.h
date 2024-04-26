#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
// is this struct really needed?
//struct entityImage
//{
//    //std::string running;
//    std::string idling;
//    //std::string attacking;
//};

namespace characterImage {
    std::vector<std::string> Nian{
        "resources\\sheet\\still\\nianstill.png",
        "resources\\sheet\\nian.png"
    };
    std::vector<std::string> Saga{
        "resources\\sheet\\still\\Sagastill.png",
        "resources\\sheet\\saga.png"
    };
    std::vector<std::string> April{
        "resources\\sheet\\still\\aprilstill.png",
        "resources\\sheet\\april.png"
    };
    std::vector<std::string> Dog{
        "resources\\sheet\\still\\dogstill.png",
        "resources\\sheet\\dogsheet.png"
    };
    std::vector<std::string> Soldier{
        "resources\\sheet\\still\\solstill.png",
        "resources\\sheet\\sol.png" 
    };
    std::vector<std::string> Lock{
        "resources\\sheet\\still\\lockstill.png",
        "resources\\sheet\\bigsadlock.png"
    };
}
namespace skillImage {
    std::vector<std::string> Nian{
        "resources\\skill_icon\\aa.png",
        "resources\\skill_icon\\nians2.png"
    };
    std::vector<std::string> Saga{
        "resources\\skill_icon\\aa.png",
        "resources\\skill_icon\\sagas2.png"
    };
    std::vector<std::string> April{
        "resources\\skill_icon\\aa.png",
        "resources\\skill_icon\\aprils2.png"
    };
    std::vector<std::string> Dog{
        "resources\\skill_icon\\aa.png",
        "resources\\skill_icon\\dogs2.png"
    };
    std::vector<std::string> Soldier{
        "resources\\skill_icon\\aa.png",
        "resources\\skill_icon\\soldiers2.png"
    };
    std::vector<std::string> Lock{
        "resources\\skill_icon\\aa.png",
        "resources\\skill_icon\\locks2.png"
    };
}
namespace imageBundle {
    const std::unordered_map<int, std::pair<std::vector<std::string>, std::vector<std::string> > > bundle = {
        {1, std::make_pair(characterImage::Nian, skillImage::Nian)},
        {2, std::make_pair(characterImage::Saga, skillImage::Saga)},
        {3, std::make_pair(characterImage::April, skillImage::April)},
        {-1, std::make_pair(characterImage::Dog, skillImage::Dog)},
        {-2, std::make_pair(characterImage::Soldier, skillImage::Soldier)},
        {0, std::make_pair(characterImage::Lock, skillImage::Lock)}
    };
}