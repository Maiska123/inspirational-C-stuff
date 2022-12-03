    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;
   

   void clear() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}


    int test1()
    {
        string str1 = "aaa", str2 = "bbb", str3 = "ccc", str4 = "ddd", str5 = "eee", str6 = "fff";

        vector vtr = {&str1, &str2, &str3, &str4, &str5, &str6};

        for (int i=0; i<vtr.size(); i++)
            cout << *vtr[i] << ' ';
        cout << endl;

        for ( auto &it : vtr)
            cout << *it << ' ';
        cout << endl;

        return 1;
    }

