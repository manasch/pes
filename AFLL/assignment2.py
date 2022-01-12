# Regular expression for validating students srn, lists name, branch, college

import re

student_db = """
SRN: PES1UG20CS111, Name: Man, Mail: XYZ@gmail.com\n
SRN: PES1UG20CS087, Name: Aarv, Mail: ZZZ@yahoo.com\n
SRN: PES2UG20CS400, Name: Yusa, Mail: ABC@outlook.com\n
SRN: PES1UG19ME198, Name: XYZ, Mail: OOO@gmail.com\n
SRN: PES3UG21EE094, Name: IJK, Mail: XXX@gmail.com\n
SRN: PES2UG18EC100, Name: ABC, Mail: ABX@outlook.com\n
"""

SRN_REGEX = "PES[1-3]UG(1[89]|2[01])(CS|E[EC]|ME)\d{3}"

def find(pattern=SRN_REGEX):
    details = []
    x = re.compile(pattern)
    x = x.finditer(student_db)
    for match in x:
        details.append([match.start(), match.end()])
    return details

def getdetails(details):
    srn_list = []
    names, namesf = [], []
    mails, mailsf = [], []
    for _ in details:
        srn_list.append(student_db[_[0] : _[1]])
    
    students = re.split("\n", student_db)

    for student in students:
        names = find("Name.+,")
        mails = find("Mail.+")
    
    for name in names:
        namesf.append(student_db[name[0] + 6 : name[1] - 1])

    for mail in mails:
        mailsf.append(student_db[mail[0] + 6: mail[1]])

    return [namesf, mailsf, srn_list]

def printdetails(names, mails, srn, srn_list):
    print("\n")
    for i, s in enumerate(srn, 0):
        if s in srn_list:
            print(s, ": SRN FOUND\n---------------")
            print("Name: {0}\nEMail: {1}\n".format(names[i], mails[i]))
        else:
            print(s, ": SRN NOT FOUND\n---------------\n")

def main():
    srn = input("Enter SRN's: ")
    srn = re.split(" ", srn)
    details = find()
    [names, mails, srn_list] = getdetails(details)
    printdetails(names, mails, srn, srn_list)

if __name__ == "__main__":
    main()