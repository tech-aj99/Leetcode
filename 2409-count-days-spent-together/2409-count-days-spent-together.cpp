class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string aa = "";
        for(char ch : arriveAlice){
            if(isalnum(ch)){
                aa += ch;
            }
        }

        string la = "";
        for(char ch : leaveAlice){
            if(isalnum(ch)){
                la += ch;
            }
        }

        string ab = "";
        for(char ch : arriveBob){
            if(isalnum(ch)){
                ab += ch;
            }
        }

        string lb = "";
        for(char ch : leaveBob){
            if(isalnum(ch)){
                lb += ch;
            }
        }

        int start = max(stoi(aa), stoi(ab));
        int end = min(stoi(la), stoi(lb));

        if(start > end) return 0;

        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        auto convert = [&] (int date){
            int month = date / 100;
            int day = date % 100;

            int total = day;
            for(int i=1;i<month;i++){
                total += days[i];
            }
            return total;
        };
        return convert(end) - convert(start) + 1;
     }
};