
#include "../../applications/organizer/week.h"

class OrganizerData
{

protected:
    Week week;

public:

    OrganizerData(){}

    std::string getMenu() {
        std::string output = "Welcome\n";
        output.append("What you want to do?\nAdd a Task [1]\nRemove a Task [2]\nEdit a Task [3]\nView a day [4]\nView a week [5]\nExit[6]\n");
        return output;
    }

    std::string ProcessRequest(std::string &request) {

        std::string word;
        std::stringstream stream(request);
        stream >> word;

        if(word == "ADD") {
            int day; std::string title;
            stream >> day;
            getline(stream, title);
            if(week.addTask(title, day))
                return "SUCCESS ADD";
        }

        if(word == "DEL") {
            int day, index;
            stream >> day >> index;
            if(week.removeTask(day, index))
                return "SUCCESS DEL";
        }

        if(word == "EDIT") {
            int day, index; std::string title;
            stream >> day >> index;
            getline(stream, title);
            if(week.editTask(day, index, title))
                return "SUCCESS EDIT";
        }

        if(word == "DAY") {
            int day; stream >> day;
            return week.getDaySchedule(day);
        }

        if(word == "WEEK")
            return week.getWeekSchedule();

        return "ERROR";
    }
};
