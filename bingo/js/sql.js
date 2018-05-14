const Query =(query) =>fetch('http://120.25.205.159:3000', {
    method:'POST',
    headers:{
        'Content-Type':'application/json'
    },
    body:JSON.stringify({
        query,
    })
});
function query(query,callback) {
    query="query "+query;
    Query(query).then(function (res) {
        res.json().then(function (ress) {
            callback(ress.data);
        })
    })
}
function mutation(query,callback) {
    query="mutation "+query;
    Query(query).then(function (res) {
        res.json().then(function (ress) {
            callback(ress.data);
        })
    })
}

function findAllBigClass(callback) {
    query("{products(sort:{type:1},limit:9999){type}}",function (result) {
        result=result.products;
        if(result.length===0) {
            callback([]);
        }else{
            var ret=[result[0].type];
            for(var i=1;i<result.length;i++){
                if(ret[ret.length-1]!==result[i].type){
                    ret.push(result[i].type);
                }
            }
            callback(ret);
        }
    })
}

function findProductByType(type,callback) {
    var sql="{products(condition:{type:\""+type+"\"}sort:{name:1},limit:9999){name,price}}";
    query(sql,function (result) {
        callback(result.products);
    })
}
function findMember(key,callback) {
    var sql="{members(condition:{name:\""+key+"\"},limit:9999){name,number}}";
    query(sql,function (result) {
        callback(result.members);
    })
}
function findMemberByNumber(id,callback) {
    var sql="{members(condition:{number:\""+id+"\"},limit:9999){name,gender,birthday,balance,isStaff,number,tel,id}}";
    query(sql,function (result) {
        callback(result.members[0]);
    })
}
function addMember(sql,callback) {
    mutation(sql,function (result) {
        callback(result);
    })
}
function cost(id,amount,callback) {
    var sql="{updateMemberBalanceTopup(id:\""+id+"\",amount:"+(-amount)+"){id}}";
    mutation(sql,function (result) {
        callback(result);
    })
}
function charge(id,amount,callback) {
    var sql="{updateMemberBalanceTopup(id:\""+id+"\",amount:"+amount+"){id}}";
    mutation(sql,function (result) {
        callback(result);
    })
}

function hash_pas(pas){
    var size=pas.length;
    var res =pas.split("");
    for(var i=0;i<size;i++){
        res[i]=res[i];
    }
    alert(res.toString());
    return(res.toString());
}