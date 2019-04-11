import pandas as pd

data = pd.read_csv("30_falls.csv")

data.columns.values

data = data.drop(["epoc (ms)", "timestamp (-0400)"], axis=1)

data["fall"] = 0

data.to_csv("partially_labeled_data.csv", index=False)
