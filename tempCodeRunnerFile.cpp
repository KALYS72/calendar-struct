void newDay(int d, int m, int y) {
        int old_d, old_m, old_y = day, month, year;
        day = d;
        month = m;
        year = y;
        if (isValidDate()) {
            cout << "Done!";
        }
        else {
            day = old_d;
            month = old_m;
            year = old_y;
            cout << "Inputs are wrong! Try again!";
        }
    }