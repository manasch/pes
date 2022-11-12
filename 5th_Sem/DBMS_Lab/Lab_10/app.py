import streamlit as st
from create import create
from database import create_table
from delete import delete
from view import view
from update import update

def main():
    st.title("Train Database System")
    st.caption("Manas Chebrolu, PES1UG20CS111")
    menu = ["Add", "View", "Update", "Remove"]
    choice = st.sidebar.selectbox("Menu", menu)
    create_table()

    if choice == "Add":
        st.subheader("Enter Train Details")
        create()
    elif choice == "View":
        st.subheader("View Train Details")
        view("View all Trains")
    elif choice == "Update":
        st.subheader("Update Train Details")
        update()
    elif choice == "Remove":
        st.subheader("Delete Train Details")
        delete()
    else:
        st.subheader("Home")

if __name__ == "__main__":
    main()
