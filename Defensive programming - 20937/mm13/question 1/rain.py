Rainfull_mi = "45, 65, 70.4, 82.6, 20.1, 90.8, 76.1, 30.92, 46.8, 67.1, 79.9"

months_rainy_num = len([month for month in Rainfull_mi.split(", ") if float(month) > 75])
