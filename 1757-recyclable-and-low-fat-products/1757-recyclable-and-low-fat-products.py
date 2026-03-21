import pandas as pd

def find_products(products: pd.DataFrame) -> pd.DataFrame:
    df=products
    x=df['low_fats']
    y=df['recyclable']
    res=(x=='Y') & (y=='Y')
    return df[res][['product_id']]