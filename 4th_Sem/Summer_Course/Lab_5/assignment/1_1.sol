// SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.8.7;

contract C {
    // private state variable
    uint private data;

    // public state variable
    uint public info;

    // constructor
    constructor() public {
        info = 10;
    }

    // private function
    function increment(uint a) private pure returns(uint) { return a + 1; }

    // public function
    function updateData(uint a) public { data = a; }
    function getData() public view returns(uint) { return data; }
    function compute(uint a, uint b) public pure returns(uint) { return a + b; }
}

// External Contract
contract D {
    function readData() public returns(uint) {
        C c =  new C();
        c.updateData(7);
        return c.getData();
    }
}

// Derived Contract
contract ReceiveEther {
    constructor() public {
    }

    receive() external payable{}
    address ownder2 = msg.sender;

    function Balance() public view returns(uint) {
        return ownder2.balance;
    }
}

contract SendEther {
    // address owner = msg.sender;
    function sendViaTransfer(address payable _to) public payable {
        // This function is no longer recommended for sending Ether.
        _to.transfer(msg.value);
    }
}
