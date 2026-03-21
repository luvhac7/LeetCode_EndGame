import pandas as pd

def find_customers(customers: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    df1=customers
    df2=orders
    mg=pd.merge(df1,df2,left_on='id',right_on='customerId',how='left')
    no=mg[mg['customerId'].isna()]
    res=no[['name']].rename(columns={'name':'Customers'})
    return res
