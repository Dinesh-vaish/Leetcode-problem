import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    salary=employee["salary"].drop_duplicates()
    if len(salary)<2:
        second =None
    else:
        second =salary.nlargest(2).iloc[-1]
    return pd.DataFrame({"SecondHighestSalary":[second]})