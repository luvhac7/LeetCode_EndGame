import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    df=world
    x=df['area']
    y=df['population']
    res=(x>=3000000)|(y>=25000000)
    return df[res][['name','population','area']]