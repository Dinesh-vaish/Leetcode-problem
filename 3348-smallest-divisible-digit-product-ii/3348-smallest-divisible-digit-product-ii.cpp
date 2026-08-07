class Solution {
public:
    using ll = long long;

    // required ko digits 2..9 mein todkar
    // smallest possible digit string banata hai.
    string factorString(ll required) {
        string s;

        for (int digit = 9; digit >= 2; digit--) {
            while (required % digit == 0) {
                s.push_back(char('0' + digit));
                required /= digit;
            }
        }

        // 2,3,5,7 ke alawa koi factor tha
        if (required != 1)
            return "";

        // Number ko smallest banane ke liye ascending order
        reverse(s.begin(), s.end());

        return s;
    }

    string smallestNumber(string num, long long t) {

        int n = num.size();

        // ------------------------------------------------
        // 1. Check whether t can be formed using digits 1..9
        // ------------------------------------------------

        ll temp = t;

        for (int p : {2, 3, 5, 7}) {
            while (temp % p == 0) {
                temp /= p;
            }
        }

        // t contains some prime other than 2,3,5,7
        if (temp != 1)
            return "-1";


        // ------------------------------------------------
        // 2. remaining[i] = required factor before index i
        // ------------------------------------------------

        vector<ll> remaining(n + 1, t);

        int zeroPos = n;

        for (int i = 0; i < n; i++) {

            int digit = num[i] - '0';

            if (digit == 0) {
                zeroPos = i;
                break;
            }

            remaining[i + 1] =
                remaining[i] /
                gcd(remaining[i], (ll)digit);
        }


        // ------------------------------------------------
        // 3. Original number already satisfies condition
        // ------------------------------------------------

        if (zeroPos == n && remaining[n] == 1)
            return num;


        // ------------------------------------------------
        // 4. Try changing one digit from right to left
        // ------------------------------------------------

        int start = (zeroPos == n ? n - 1 : zeroPos);

        for (int i = start; i >= 0; i--) {

            ll required = remaining[i];

            int freeSlots = n - 1 - i;

            int currentDigit = num[i] - '0';

            // IMPORTANT:
            // Only BIGGER digit, because same digit can
            // produce a smaller suffix than num.
            for (int digit = max(1, currentDigit + 1);
                 digit <= 9;
                 digit++) {

                // Current digit satisfies some part of required
                ll furtherRequired =
                    required /
                    gcd(required, (ll)digit);

                string suffix = factorString(furtherRequired);

                // Required factors fit into remaining slots
                if ((int)suffix.size() <= freeSlots) {

                    int ones = freeSlots - suffix.size();

                    return num.substr(0, i)
                         + char('0' + digit)
                         + string(ones, '1')
                         + suffix;
                }
            }
        }


        // ------------------------------------------------
        // 5. If same length doesn't work,
        //    construct a number with more digits
        // ------------------------------------------------

        string suffix = factorString(t);

        if (suffix.empty() && t != 1)
            return "-1";

        // At least n+1 digits are required to be > num
        int length = max(n + 1, (int)suffix.size());

        return string(length - suffix.size(), '1') + suffix;
    }
};