class Solution {
    vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
public:
    string dayOfTheWeek(int day, int month, int year) {
        if (month < 3) {
            month += 12;
            year--;
        }
        int K = year % 100;
        int J = year / 100;
        int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) + 5 * J) % 7;
        int index = (h + 6) % 7;
        return days[index];
    }
};
