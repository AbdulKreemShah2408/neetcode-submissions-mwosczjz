class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int>roomCount(n,0);
        priority_queue<int,vector<int>,greater<int>>freeRooms;
        for(int i=0;i<n;i++){
            freeRooms.push(i);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        for(auto& meeting:meetings){
            long long start=meeting[0];
            long long end=meeting[1];
            long long duration=end-start;
            while(!busyRooms.empty() && busyRooms.top().first<=start){
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            if(!freeRooms.empty()){
                int rooms=freeRooms.top();
                freeRooms.pop();
                busyRooms.push({end,rooms});
                roomCount[rooms]++;
            }else{
                auto earliestFree=busyRooms.top();
                busyRooms.pop();
                long long roomAvailableTime=earliestFree.first;
                int room=earliestFree.second;
                long long newEnd=roomAvailableTime+duration;
                busyRooms.push({newEnd,room});
                roomCount[room]++;
            }
        }
        int maxMeetings=-1;
        int resultRoom=0;
        for(int i=0;i<n;i++){
            if(roomCount[i]>maxMeetings){
                maxMeetings=roomCount[i];
                resultRoom=i;
            }
        }
        return resultRoom;
    }
};