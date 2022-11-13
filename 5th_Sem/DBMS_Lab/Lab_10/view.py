import pandas as pd
import streamlit as st
from database import view_all_data

def view(expander_heading):
    result = view_all_data()
    df = pd.DataFrame(result, columns=["Train No", "Train Name", "Train Type", "Source", "Destination", "Availability"])
    df.index += 1

    with st.expander(expander_heading):
        st.dataframe(df)
