// SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.7;

contract XYZ {
    constructor() public{
    }

    function Set_Method(uint a1, uint a_m) public pure returns(uint[] memory) {
        uint[] memory table = new uint[](a1);

        for (uint i = 0; i < a1; i++) {
            table[i] = a_m * i;
        }

        return table;
    }
}
