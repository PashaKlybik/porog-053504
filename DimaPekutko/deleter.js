let args = process.argv
let fs = require('fs');
let data = fs.readFileSync('data.json');
let json = JSON.parse(data);
let users = json.users;
let deleteId;
json.users = users.filter((user) => { 
    return user.id != args[2]; 
});
fs.writeFileSync('data.json', JSON.stringify(json, null, 2));
