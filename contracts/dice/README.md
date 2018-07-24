DICE
-----------------

This contract implements a simple DICE game between two players with 50/50 odds of winning. 

Before playing all players deposit funds into their @dice account just like the @exchange contract

1. Player 1 proposes to bet 1 VAC and submits SHA256(secret1)
2. Player 2 proposes to bet 1 VAC and submits SHA256(secret2)

Because Player 1 and 2 bet equal amounts their orders are matched and the game begins.

3. A Player reveales their secret
4. A 5 minute deadline starts whereby the first to reveal automatically wins unless the other player reveals
5. The other player reveals and a winner is chosen and paid based upon the value of sha256( cat(secret1,secret2) )
6. After the deadline anyone can trigger a default claim and the rewards


Economic Incentive for Interface Developers
-----------------

A variation on this game would be to add an additional information on offer creation that will get paid
a commission when the player wins. With this commission in place there is financial incentive for a
service provider to continue to execute the game in a timely manner as well as provide quality and
entertaining interfaces on top of this game.


Other Games
-----------
This same basic model can be used to build more robust games.


Potential Vulnerabilities
-------
1. Block Producers may exclude reveal transaction 
2. Losers may force winner to wait 5 minutes to get rewards
3. Service providers may fail to auto-reveal on your behalf
4. You may lose internet connectivity mid-game
5. A blockhain reorganization could cause some havock if secrets are revealed too quickly
    - @dice could protect users by rejecting reveals until a game creation is irreversible (about 45 seconds max)
    - users could take risk themselves by deciding how many confirmations are required
    - for small amounts it probably doesn't matter 
    - under normal operation of DPOS chains there are few if any chain reorganizations


Example game session using clVAC
-------
#### Prerequisites
* Wallet must be unlock and have at least the following private keys

	**5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3**
	**5Jmsawgsp1tQ3GD6JyGCwy1dcvqKZgX6ugMVMdjirx85iv5VyPR**

##### Upload bios contract
````bash
clVAC set contract VACCOIN build/contracts/VACCOIN.bios -p VACCOIN
````

##### Ceate VACCOIN.token account
````bash
clVAC create account VACCOIN VACCOIN.token VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4 VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4
````

##### Set VACCOIN.token contract to VACCOIN.token account
````bash
clVAC set contract VACCOIN.token build/contracts/VACCOIN.token -p VACCOIN.token
````

##### Create dice account
````bash
clVAC create account VACCOIN dice VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4 VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4
````

##### Set dice contract to dice account
````bash
clVAC set contract dice build/contracts/dice -p dice
````

##### Create native VAC token
````bash
clVAC push action VACCOIN.token create '[ "VACCOIN", "1000000000.0000 VAC", 0, 0, 0]' -p VACCOIN.token
````

##### Create alice account
````bash
clVAC create account VACCOIN alice VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4 VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4
````

##### Create bob account
````bash
clVAC create account VACCOIN bob VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4 VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4
````

##### Issue 1000 VAC to alice
````bash
clVAC push action VACCOIN.token issue '[ "alice", "1000.0000 VAC", "" ]' -p VACCOIN
````

##### Issue 1000 VAC to bob
````bash
clVAC push action VACCOIN.token issue '[ "bob", "1000.0000 VAC", "" ]' -p VACCOIN
````

##### Allow dice contract to make transfers on alice behalf (deposit)
````bash
clVAC set account permission alice active '{"threshold": 1,"keys": [{"key": "VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4","weight": 1}],"accounts": [{"permission":{"actor":"dice","permission":"active"},"weight":1}]}' owner -p alice
````

##### Allow dice contract to make transfers on bob behalf (deposit)
````bash
clVAC set account permission bob active '{"threshold": 1,"keys": [{"key": "VAC7ijWCBmoXBi3CgtK7DJxentZZeTkeUnaSDvyro9dq7Sd1C3dC4","weight": 1}],"accounts": [{"permission":{"actor":"dice","permission":"active"},"weight":1}]}' owner -p bob
````

##### Alice deposits 100 VAC into the dice contract
````bash
clVAC push action dice deposit '[ "alice", "100.0000 VAC" ]' -p alice
````

##### Bob deposits 100 VAC into the dice contract
````bash
clVAC push action dice deposit '[ "bob", "100.0000 VAC" ]' -p bob
````

##### Alice generates a secret
````bash
openssl rand 32 -hex
28349b1d4bcdc9905e4ef9719019e55743c84efa0c5e9a0b077f0b54fcd84905
````

##### Alice generates sha256(secret)
````bash
echo -n '28349b1d4bcdc9905e4ef9719019e55743c84efa0c5e9a0b077f0b54fcd84905' | xxd -r -p | sha256sum -b | awk '{print $1}'
d533f24d6f28ddcef3f066474f7b8355383e485681ba8e793e037f5cf36e4883
````

##### Alice bets 3 VAC
````bash
clVAC push action dice offerbet '[ "3.0000 VAC", "alice", "d533f24d6f28ddcef3f066474f7b8355383e485681ba8e793e037f5cf36e4883" ]' -p alice
````

##### Bob generates a secret
````bash
openssl rand 32 -hex
15fe76d25e124b08feb835f12e00a879bd15666a33786e64b655891fba7d6c12
````

##### Bob generates sha256(secret)
````bash
echo -n '15fe76d25e124b08feb835f12e00a879bd15666a33786e64b655891fba7d6c12' | xxd -r -p | sha256sum -b | awk '{print $1}'
50ed53fcdaf27f88d51ea4e835b1055efe779bb87e6cfdff47d28c88ffb27129
````

##### Bob also bets 3 VAC (a game is started)
````bash
clVAC push action dice offerbet '[ "3.0000 VAC", "bob", "50ed53fcdaf27f88d51ea4e835b1055efe779bb87e6cfdff47d28c88ffb27129" ]' -p bob
````

##### Dice contract tables right after the game started
````bash
clVAC get table dice dice account
````
````json
{
  "rows": [{
      "owner": "alice",
      "VAC_balance": "97.0000 VAC",
      "open_offers": 0,
      "open_games": 1
    },{
      "owner": "bob",
      "VAC_balance": "97.0000 VAC",
      "open_offers": 0,
      "open_games": 1
    }
  ],
  "more": false
}
````

````bash
clVAC get table dice dice game
````
````json
{
  "rows": [{
      "id": 1,
      "bet": "3.0000 VAC",
      "deadline": "1970-01-01T00:00:00",
      "player1": {
        "commitment": "d533f24d6f28ddcef3f066474f7b8355383e485681ba8e793e037f5cf36e4883",
        "reveal": "0000000000000000000000000000000000000000000000000000000000000000"
      },
      "player2": {
        "commitment": "50ed53fcdaf27f88d51ea4e835b1055efe779bb87e6cfdff47d28c88ffb27129",
        "reveal": "0000000000000000000000000000000000000000000000000000000000000000"
      }
    }
  ],
  "more": false
}
````

##### Bob reveals his secret
````bash
clVAC push action dice reveal '[ "50ed53fcdaf27f88d51ea4e835b1055efe779bb87e6cfdff47d28c88ffb27129", "15fe76d25e124b08feb835f12e00a879bd15666a33786e64b655891fba7d6c12" ]' -p bob
````

##### Game table after bob revealed (now the game has a deadline for alice to reveal)
````bash
clVAC get table dice dice game
````
````json
{
  "rows": [{
      "id": 1,
      "bet": "3.0000 VAC",
      "deadline": "2018-04-17T07:45:49",
      "player1": {
        "commitment": "d533f24d6f28ddcef3f066474f7b8355383e485681ba8e793e037f5cf36e4883",
        "reveal": "0000000000000000000000000000000000000000000000000000000000000000"
      },
      "player2": {
        "commitment": "50ed53fcdaf27f88d51ea4e835b1055efe779bb87e6cfdff47d28c88ffb27129",
        "reveal": "15fe76d25e124b08feb835f12e00a879bd15666a33786e64b655891fba7d6c12"
      }
    }
  ],
  "more": false
}
````

##### Alice reveals her secret (the winner is determined, the game is removed)
````bash
clVAC push action dice reveal '[ "d533f24d6f28ddcef3f066474f7b8355383e485681ba8e793e037f5cf36e4883", "28349b1d4bcdc9905e4ef9719019e55743c84efa0c5e9a0b077f0b54fcd84905" ]' -p alice
````

##### Balance of the accounts after game ends
````bash
clVAC get table dice dice account
````
````json
{
  "rows": [{
      "owner": "alice",
      "VAC_balance": "103.0000 VAC",
      "open_offers": 0,
      "open_games": 0
    },{
      "owner": "bob",
      "VAC_balance": "97.0000 VAC",
      "open_offers": 0,
      "open_games": 0
    }
  ],
  "more": false
}
````

##### Alice withdraw from her dice account 103 VAC
````bash
clVAC push action dice withdraw '[ "alice", "103.0000 VAC" ]' -p alice
````

##### Balance of alice after withdraw
````bash
clVAC get currency balance VACCOIN.token alice VAC
1003.0000 VAC
````
