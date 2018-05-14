want=[];
currmember={};
total=0;
Array.prototype.remove = function(from, to) {
    var rest = this.slice((to || from) + 1 || this.length);
    this.length = from < 0 ? this.length + from : from;
    return this.push.apply(this, rest);
};
function decrease(name) {
    for(var i=0;i<want.length;i++){
        if(want[i].name===name){
            want[i].amount--;
            if(want[i].amount===0)
                want.remove(i,i);
        }
    }
    updateOrder();
}
function increase(name) {
    for(var i=0;i<want.length;i++){
        if(want[i].name===name)
            want[i].amount++;
    }
    updateOrder();
}
function updateOrder() {
    var head="<tr><th>产品名称</th><th>价格</th><th>减少</th><th>数量</th><th>增加</th></tr>";
    var dis=head;
    total=0;
    for(var i=0;i<want.length;i++) {
        dis += "<tr><td>" + want[i].name + "</td><td>" + want[i].price + "</td><td onclick='decrease(\"" + want[i].name + "\")'>减少</td><td>" + want[i].amount + "</td><td onclick='increase(\"" + want[i].name + "\")'>增加</td></tr>";
        total+=want[i].price*want[i].amount;
    }
    dis+="<tr><td colspan='2'>TOTAL</td><td colspan='3'>"+total+"</td></tr>";
    $("#tableoforder").html(dis);
}
function addItem(name,price) {
    for(var i=0;i<want.length;i++){
        if(want[i].name===name){
            want[i].amount++;
            updateOrder();
            return;
        }
    }
    want.push({
        name:name,
        amount:1,
        price:price,
    });
    updateOrder();
}
function updateProductList(type) {
    findProductByType(type,function (result) {
        var dis = "";
        for (var i = 0; i < result.length; i++) {
            dis+="<tr ondblclick=\'addItem(\""+result[i].name+"\","+result[i].price+")\'><td>"+result[i].name+"</td></tr>";
        }
        $("#tableofdetailproduct").html(dis);
    })
}
function updateMemberTable(number) {
    findMemberByNumber(number,function (result) {
        currmember=result;
        $("#td1").text(result.name);
        if(result.gender==="MALE")
            $("#td2").text("汉子");
        else if(result.gender==="FEMALE")
            $("#td2").text("妹子");
        else
            $("#td2").text("未知");
        $("#td3").text(result.birthday);
        $("#td4").text(result.balance);
        if(result.isStaff)
            $("#td5").text("是");
        else
            $("#td5").text("否");
        $("#td6").text(result.number);
        $("#td7").text(result.tel);
        $("#td12").text(result.name);
        if(result.gender==="MALE")
            $("#td22").text("汉子");
        else if(result.gender==="FEMALE")
            $("#td22").text("妹子");
        else
            $("#td22").text("未知");
        $("#td32").text(result.birthday);
        $("#td42").text(result.balance);
        if(result.isStaff)
            $("#td52").text("是");
        else
            $("#td52").text("否");
        $("#td62").text(result.number);
        $("#td72").text(result.tel);
    })
}
function init() {
    //  初始化
    //  样式、初始标签
    //$(".section").css("width", $("#body").width() - $("#nav").width()).hide();
    $("#buy").show();
    //  更新表格
    //$("#list").empty();
    $("#tableofdetailproduct").empty();
    findAllBigClass(function (result) {
        var itemleft = "<tr onclick='updateProductList(\"";
        var itemmiddle="\")'><td>";
        var itemright = "</td></tr>";
        var dis = "";
        for (var i = 0; i < result.length; i++) {
            dis+=itemleft+result[i]+itemmiddle+result[i]+itemright;
        }
        $("#tableofbigclass").html(dis);
    });
}
function btn() {

    //  按钮功能
    $("#buybtn").click(function () {
        $(".section").hide();
        $("#buy").show();
    });
    $("#regbtn").click(function () {
        $(".section").hide();
        $("#reg").show();
    });
    $("#rmbtn").click(function () {
        $(".section").hide();
        $("#rm").show();
    });
    $("#modifybtn").click(function () {
        $(".section").hide();
        $("#modify").show();
    });
    $("#input_1").keyup(function () {
        var val=$("#input_1").val();
        findMember(val,function (result) {
            var dis="";
            for(var i=0;i<result.length;i++){
                dis+="<li onclick='updateMemberTable(\""+result[i].number+"\")'>"+result[i].name+"</li>";
            }
            $("#list").html(dis);
        })
    });
    $("#input_2").keyup(function () {
        var val=$("#input_2").val();
        findMember(val,function (result) {
            var dis="";
            for(var i=0;i<result.length;i++){
                dis+="<li onclick='updateMemberTable(\""+result[i].number+"\")'>"+result[i].name+"</li>";
            }
            $("#list2").html(dis);
        })
    });
    $("#submit1").click(function () {
        if(total>currmember.balance)
            alert("余额不足");
        else {
            cost(currmember.id,total,function (result) {
                updateMemberTable(currmember.number);
                want=[];
                updateOrder();
                alert("成功");
                //新建订单
            })
        }
    });
    $("#submit2").click(function () {
        var username=$("#username").val();
        var tel=$("#tel").val();
        var gender=$("input[name='sex']:checked").val();
        var number=$("#number").val();
        var birthday=$("#birth").val();
        var isStaff=$("input[name='staff']:checked").val();
        isStaff=isStaff==="isstaff";
        var balance=$("#balance").val();
        var abbr=pinyinString(username)+tel+"#"+number+"#";
        sql="{createMember(name:\""+username+"\",tel:\""+tel+"\",gender:"+gender+",number:\""+number+"\",birthday:\""+birthday+"\",isStaff:"+isStaff+",balance:"+balance+",abbr:\""+abbr+"\") {id}}";
        addMember(sql,function (result) {
            //console.log(result);
        })
    });
    $("#submit3").click(function () {
       var money=$("#input_3").val();
       charge(currmember.id,money,function (result) {
           updateMemberTable(currmember.number);
           alert("成功");
       })
    });
    $("#submit_modify_passwprd").click(function () {
        var pas=$("#input_modify_passwprd").val();
        alert("1");
        var m=hash_pas(pas);
        if(m="1111"){
            alert("success");
        }
        else{
            alert("false");
        }
    })
}

function test() {
    //  test code
    //alert(pinyinString("厦门"));
}

$(document).ready(function () {
    init();
    btn();
    test();
});