// SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.7;

contract Lab_4 {
    constructor() public{
    }
    string Renter_Name = "XYA";
    uint Term = 5;
    string Security_Deposit = "5 ETH";
    string Owner_Name = "JKH";

    function Provide_Details() public view returns(string memory, uint, string memory, string memory) {
        return(Renter_Name, Term, Security_Deposit, Owner_Name);
    }
}

