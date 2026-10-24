class Solution {
public:
    int countDaysTogether(string arriveAlice,string leaveAlice,string arriveBob,string leaveBob) {
        int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
        
        int monthA1=(arriveAlice[0]-'0')*10+(arriveAlice[1]-'0');
        int dayA1=(arriveAlice[3]-'0')*10+(arriveAlice[4]-'0');
        int arriveA=dayA1;
        for(int i=0;i<monthA1-1;i++) {
            arriveA=arriveA+days[i];
        }
        
        int monthL1=(leaveAlice[0]-'0')*10+(leaveAlice[1]-'0');
        int dayL1=(leaveAlice[3]-'0')*10+(leaveAlice[4]-'0');
        int leaveA=dayL1;
        for(int i=0;i<monthL1-1;i++) {
            leaveA=leaveA+days[i];
        }
        
        int monthA2=(arriveBob[0]-'0')*10+(arriveBob[1]-'0');
        int dayA2=(arriveBob[3]-'0')*10+(arriveBob[4]-'0');
        int arriveB=dayA2;
        for(int i=0;i<monthA2-1;i++) {
            arriveB=arriveB+days[i];
        }
        
        int monthL2=(leaveBob[0]-'0')*10+(leaveBob[1]-'0');
        int dayL2=(leaveBob[3]-'0')*10+(leaveBob[4]-'0');
        int leaveB=dayL2;
        for(int i=0;i<monthL2-1;i++) {
            leaveB=leaveB+days[i];
        }
        
        int startDay=max(arriveA,arriveB);
        int endDay=min(leaveA,leaveB);
        
        if(startDay<=endDay) {
            return endDay-startDay+1;
        } else {
            return 0;
        }
    }
};