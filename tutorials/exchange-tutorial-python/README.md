The following steps must be taken for the example script to work.

0. Create wallet
0. Create account for VACio.token
0. Create account for scott
0. Create account for exchange
0. Set token contract on VACio.token
0. Create VAC token
0. Issue initial tokens to scott

**Note**:
Deleting the `transactions.txt` file will prevent replay from working.


### Create wallet
`clVAC wallet create`

### Create account steps
`clVAC create key`

`clVAC create key`

`clVAC wallet import  --private-key <private key from step 1>`

`clVAC wallet import  --private-key <private key from step 2>`

`clVAC create account VACio <account_name> <public key from step 1> <public key from step 2>`

### Set contract steps
`clVAC set contract VACio.token /contracts/VACio.token -p VACio.token@active`

### Create VAC token steps
`clVAC push action VACio.token create '{"issuer": "VACio.token", "maximum_supply": "100000.0000 VAC", "can_freeze": 1, "can_recall": 1, "can_whitelist": 1}' -p VACio.token@active`

### Issue token steps
`clVAC push action VACio.token issue '{"to": "scott", "quantity": "900.0000 VAC", "memo": "testing"}' -p VACio.token@active`
