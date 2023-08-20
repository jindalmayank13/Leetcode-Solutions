class Solution {
    string normalizeRational(string s) {
        string integer, non, rep;

        int i = 0, n = s.size();
        while (i < n && s[i] != '.') {
            integer.push_back(s[i]);
            i++;
        }

        for (i++; i < n && s[i] != '(';) {
            non.push_back(s[i]);
            i++;
        }

        for (i++; i < n && s[i] != ')';) {
            rep.push_back(s[i]);
            i++;
        }

        // compress rep
        for (i = 1; i < rep.size(); i++) {
            if (rep[0] != rep[i]) {
                break;
            }
        }

        if (i == rep.size()) {
            rep.resize(1);
        }

        if (rep.size() == 4 && rep.substr(0, 2) == rep.substr(2, 2)) {
            rep.resize(2);
        }

        while (!non.empty() && !rep.empty() && non.back() == rep.back()) {
            rep.pop_back();
            rep = non.back() + rep;
            non.pop_back();
        }

        if (rep == "0") {
            rep = "";
        }
        // carry in
        else if (rep == "9") {
            // not ends with '9' as long as not empty
            if (!non.empty()) {
                non.back() += 1;
            } else {
                for (i = integer.size() - 1; i >= 0; i--) {
                    if (integer[i] != '9') {
                        integer[i] += 1;
                        break;
                    } else {
                        integer[i] = '0';
                    }
                }

                // "999" -> "1000"
                if (i == -1) {
                    integer = "1" + integer;
                }
            }

            rep = "";
        }

        // deal with "327.300"
        if (rep.empty()) {
            while (!non.empty() && non.back() == '0') {
                non.pop_back();
            }
        }

        if (!non.empty() || !rep.empty()) {
            return integer + "." + non + (rep.empty() ? "" : "(" + rep + ")");
        }

        return integer;
    }
public:
    bool isRationalEqual(string s, string t) {
        string s2 = normalizeRational(s);
        string t2 = normalizeRational(t);

        // std::cout << s2 << " " << t2 << std::endl;
        return s2 == t2;
    }
};