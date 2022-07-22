// SPDX-License-Identifier: GPL-3.0
pragma solidity ^0.6.6;

contract BankContract {
    struct client_account{
        int client_id;
        address client_address;
        uint client_bal;
    }
    
    client_account[] clients;
    int clientcounter;
    
    constructor() public {
        clientcounter = 0;
    }

    mapping(address => uint) public interestDate;
    address payable manager;

    // manager side
    modifier onlyManager() {
        require(msg.sender == manager, "only manager can transact");
        _;
    }

    // client side
    modifier onlyClients() {
        bool isClient = false;
        for(uint i = 0; i < clients.length; i++){
            if(clients[i].client_address == msg.sender)
            {
                isClient = true;
                break;
            }
        }
        require(isClient, "only clients are allowed");
        _;
    }
    
    // fallback function--- receive the ether
    receive() external payable{}

    // methods
    function setManager(address managerAddress) public returns (string memory) {
        manager = payable (managerAddress);
        return "";
    }

    function joinAsClient() public payable returns (string memory) {
        interestDate[msg.sender] = block.timestamp;
        clients.push(client_account(clientcounter++, msg.sender, address(msg.sender).balance));
        return "";
    }

    function deposit() public payable onlyClients {
        payable(address(this)).transfer(msg.value);
    }

    function withdraw(uint amount)public payable onlyClients {
        msg.sender.transfer(amount * 1 ether);
    }

    function getContractBalance() public view returns (uint) {
        return address(this).balance;
    }
}
