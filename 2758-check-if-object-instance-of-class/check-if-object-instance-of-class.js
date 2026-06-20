/**
 * @param {*} obj
 * @param {*} classFunction
 * @return {boolean}
 */
var checkIfInstanceOf = function(obj, cf) {
    while(obj!=null)
    {
        if(obj.constructor===cf){ return true;}
    obj=Object.getPrototypeOf(obj);
}
    return false;
};

/**
 * checkIfInstanceOf(new Date(), Date); // true
 */