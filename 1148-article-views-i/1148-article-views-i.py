import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    df=views
    x=df['author_id']
    y=df['viewer_id']
    res=(x==y)
    ans=(df[res][['author_id']].rename(columns={'author_id':'id'}).drop_duplicates().sort_values(by='id',ascending=True))
    return ans