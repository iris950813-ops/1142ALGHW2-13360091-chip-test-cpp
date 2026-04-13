int findGoodChip(vector<int> chips) {
    while (!chips.empty()) {
        int n = chips.size();

        // 1. 若只剩一顆
        if (n == 1) {
            return chips[0];
        }

        // 2. 候選晶片 A
        int A = chips[0];

        // 3. 設 V = 0
        int V = 0;

        // 4. 與其他晶片互測
        for (int i = 1; i < n; i++) {
            int B = chips[i];

            if (report[A][B] && report[B][A]) {
                V++;
            }
        }

        // 5. 若 V >= n/2，回傳 A
        if (V >= n / 2) {
            return A;
        }

        // 6. 否則刪除 A
        chips.erase(chips.begin());
    }

    return -1;
}
