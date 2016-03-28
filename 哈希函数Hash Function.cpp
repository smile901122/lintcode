class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        
        int n = key.size();
        long long hashcode = 0; //long long
        for(int i = 0; i < n; ++i)
        {
            hashcode = ((hashcode * 33) + key[i]) % HASH_SIZE;
        }
        return hashcode;
        
        /*
        int n = key.size();
        long long hashcode = 0; //long long
        long long power = 1;
        for(int i = n - 1; i >= 0; --i)
        {
            hashcode += power * key[i] % HASH_SIZE;
            power *= 33;
            power %= HASH_SIZE;
            hashcode %= HASH_SIZE;
        }
        return hashcode;
        */
    }
};
