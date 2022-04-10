class Twitter
{
private:
    int times;
    unordered_map<int, vector<pair<int, int>>> userTweetMap;
    unordered_map<int, set<int>> followerMap;
public:
    Twitter() 
    {
        times = 0;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        followerMap[userId].insert(userId);
        userTweetMap[userId].push_back({times++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<pair<int, int>> latest;
        vector<int> ans;
        
        for (auto it1 = followerMap[userId].begin();it1 != followerMap[userId].end();it1++)
        {
            for (auto it2 : userTweetMap[*it1])
            {
                latest.push_back(it2);
            }
        }
        
        sort(latest.begin(), latest.end());
        
        for (int i=latest.size()-1;i>=0 && ans.size() < 10;i--)
            ans.push_back(latest[i].second);
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) 
    {
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        followerMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
