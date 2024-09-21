/*class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::sort(arr.begin(),arr.end());
        set<int> s;
        int c=1;
        for (int i=0; i<arr.size()-1;i++){
            if  (arr[i]==arr[i+1]){
                c+=1;
            }
            else {
                auto result = s.insert(c);
                if (!result.second){
                    return false;
                }
                c=1;
            }
        }
        auto result = s.insert(c);
        if (!result.second){
                    return false;
        }
        if (s.size()==set<int>(arr.begin(),arr.end()).size()){
            return true;
        }
        else {
            return false;
        }
    }
}; */


// Solution with maps

/*
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,bool> m;
        int c=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            c=1;
            while (arr[i]==arr[i+1]){
                c++; i++;
            }
            if (m[c]==true)
                return false;
            m[c]=true;
            if (i==arr.size()-2 && m[1]==true)
                return false;
        }
    return true;
    }
};
*/

/*
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,bool> map;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for (int i=0,c=1; i<n-1;i++){
            while (i<n-1 && arr[i]==arr[i+1]){
                c++;
                i++;
            }
            if (map[c]==true) return false;
            map[c]=true;
            if (i==n-2 && arr[i]!=arr[i+1] && map[1]==true) return false;
        }
        return true;
    }
};
*/