import pandas as pd
import matplotlib.pyplot as plt
from math import sqrt, pow
from scipy.signal import wiener

rolling_avg_val = 3
peak_points = 1

with open("hard_falls_collar.csv", "a") as data:
    data.write("x,y,z\n")
    for i in range(0,5):

        trough_points = []
        test_data = pd.read_csv("Data/Collar Falls/hard_fall_{}.csv".format(i + 1))

        padded_list = rolling_avg_val * [[0]]

        smoothed_x = pd.concat([pd.DataFrame(padded_list), test_data["x-axis (g)"]],
                               ignore_index=True)
        smoothed_y = pd.concat([pd.DataFrame(padded_list), test_data["y-axis (g)"]],
                               ignore_index=True)
        smoothed_z = pd.concat([pd.DataFrame(padded_list), test_data["z-axis (g)"]],
                               ignore_index=True)

        smoothed_x = test_data["x-axis (g)"].rolling(rolling_avg_val).mean()
        smoothed_y = test_data["y-axis (g)"].rolling(rolling_avg_val).mean()
        smoothed_z = test_data["z-axis (g)"].rolling(rolling_avg_val).mean()

        smoothed_x = smoothed_x.fillna(0)
        smoothed_y = smoothed_y.fillna(0)
        smoothed_z = smoothed_z.fillna(0)

        trough_points.append(list(smoothed_x.nsmallest(peak_points))[0])
        trough_points.append(list(smoothed_y.nsmallest(peak_points))[0])
        trough_points.append(list(smoothed_z.nsmallest(peak_points))[0])

        for i in range(0,3):
            if i == 2:
                data.write(str(trough_points[i]) + "\n")
            else:
                data.write(str(trough_points[i]) + ",")

with open("soft_falls_collar.csv", "a") as data:
    data.write("x,y,z\n")
    for i in range(0,5):

        trough_points = []
        test_data = pd.read_csv("Data/Collar Falls/soft_fall_{}.csv".format(i + 1))
        test_data.columns.values

        test_data
        padded_list = rolling_avg_val * [[0]]

        smoothed_x = pd.concat([pd.DataFrame(padded_list), test_data["x-axis (g)"]],
                               ignore_index=True)
        smoothed_y = pd.concat([pd.DataFrame(padded_list), test_data["y-axis (g)"]],
                               ignore_index=True)
        smoothed_z = pd.concat([pd.DataFrame(padded_list), test_data["z-axis (g)"]],
                               ignore_index=True)

        smoothed_x = test_data["x-axis (g)"].rolling(rolling_avg_val).mean()
        smoothed_y = test_data["y-axis (g)"].rolling(rolling_avg_val).mean()
        smoothed_z = test_data["z-axis (g)"].rolling(rolling_avg_val).mean()

        smoothed_x = smoothed_x.fillna(0)
        smoothed_y = smoothed_y.fillna(0)
        smoothed_z = smoothed_z.fillna(0)

        trough_points.append(list(smoothed_x.nsmallest(peak_points))[0])
        trough_points.append(list(smoothed_y.nsmallest(peak_points))[0])
        trough_points.append(list(smoothed_z.nsmallest(peak_points))[0])


        for i in range(0,3):
            if i == 2:
                data.write(str(trough_points[i]) + "\n")
            else:
                data.write(str(trough_points[i]) + ",")
