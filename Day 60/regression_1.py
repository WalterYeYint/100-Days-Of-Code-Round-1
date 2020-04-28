import pandas as pd
import quandl
import math

df = quandl.get("BSE/BOM511636")

df = df[['Open', 'High', 'Low', 'Close',]]
df['HL_PCT'] = (df['High'] - df['Close']) / df['Close'] * 100.0
df['PCT_change'] = (df['Close'] - df['Open']) / df['Open'] * 100.0

df = df[['Close', 'HL_PCT', 'PCT_change',]]

forecast_col = 'Close'
df.fillna(-99999, inplace = True)

#math.ceil rounds off to nearest whole
#but seems to return a float, so casted with int
forecast_out = int(math.ceil(0.01 * len(df)))    

#labels
df['label'] = df[forecast_col].shift(-forecast_out)
df.dropna(inplace = True)
print(df.head())