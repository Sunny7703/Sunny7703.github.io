class Solution {
public:
    bool isPowerOfTwo(int n) {
        bool r = true;
        while(n != 1)
        {
            if(n % 2 == 1)
            {
                true = false;
                return r;
            }
            n /= 2;
        }
        return r;
    }
    int main()
    {
        int n;
        cin >> n;
        bool r = isPowerOfTwo(n);
        cout << r << endl;
    }
};
