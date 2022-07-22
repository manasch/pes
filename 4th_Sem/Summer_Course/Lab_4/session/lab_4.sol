// SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.7;

// No print statements, so can't display anything, the getter function will be able to access public decalred variables

contract Lab4 {
    uint public a = 10; // state variable
    bool b;
    // uint c = block.difficulty; // global variable

    constructor() public {
        // 20 bytes, rest automatically filled with 0 if not mentioned
        // address x = 0x213456; Hardcoded
        // address = msg.sender -> current node's address

        b = false;
    }

    function f() public pure returns(uint) {
        uint q = 12; // local variable
        uint p = 45;
        uint result = (2 ** (p - q));
        return result;
    }

    /*
        whenever using string or array, do the following
        string _____ name = "test"

        fill in the blank with either "memory" or "storage"
        memory -> RAM or temporary storage --> The gas consumption would be low
        storage -> ROM or permanent storage --> The gas consumption would be higher

        Using bytes data type
            bytesX -> X represents the number of bytes to reserve, less gas consumption
            bytes by default takes 1 byte
        
        Representing arrays
            type arrayName[arraySize]
            uint a[10];

            dynamically declaring ararys
            uint[] data = new uint[](size);
        
        ## Strings don't have array indexing, no concatenation
        ## Arrays have length, push and pop
    */

    function f2() public pure returns(uint, uint, uint, string memory) {
        uint[] memory arr = new uint[](6);
        string memory str = "Hello World";

        for (uint i = 0; i < 6; i++) {
            arr[i] = i;
        }
        return (arr[0], arr[1], arr[2], str);
    }

    /*
        function f(uint a, uint b) public pure returns (uint result) {
            uint result = a + b;
        }
        ## Don't have to mention return result
    */

    // function parameter
    
    function f3(uint a) public pure returns(uint) {
        return ++a;
    }

    function f4() public view returns(uint, address){
        // if exchange of ethers is required, then the keyword payable is required
        address x = msg.sender;
        if(x.balance > 5000) {
            return (x.balance, x);
        }
    }

    // send and receive of ethers can't happen on the same contract

    /*
        view functions won't modify state variable
        pure functions won't allow reading or modification of state variables
    */
}