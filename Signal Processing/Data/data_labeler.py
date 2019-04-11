import pandas as pd

data = pd.read_csv("partially_labeled_data.csv")

data.loc[332:413] = 1
data.loc[615:695] = 1
data.loc[915:993] = 1
data.loc[1260:1328] = 1
data.loc[1645:1693] = 1
data.loc[1889:1956] = 1
data.loc[2319:2381] = 1
data.loc[2628:2697] = 1
data.loc[2990:3046] = 1
data.loc[3233:3285] = 1
data.loc[3490:3538] = 1
data.loc[3733:3785] = 1
data.loc[4015:4071] = 1
data.loc[4258:4310] = 1
data.loc[4621:4666] = 1
data.loc[4920:4968] = 1
data.loc[5133:5178] = 1
data.loc[5459:5516] = 1
data.loc[5784:5835] = 1
data.loc[6029:6076] = 1
data.loc[6354:6406] = 1
data.loc[6673:6831] = 1
data.loc[7028:7076] = 1
data.loc[7318:7382] = 1
data.loc[7733:7794] = 1
data.loc[8390:8434] = 1
data.loc[8604:8662] = 1
data.loc[8765:8816] = 1
data.loc[8952:9004] = 1
data.loc[9141:9177] = 1
