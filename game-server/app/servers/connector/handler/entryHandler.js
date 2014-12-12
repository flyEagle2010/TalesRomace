module.exports = function(app) {
  return new Handler(app);
};

var Handler = function(app) {
  this.app = app;
};


Handler.prototype.test = function(msg, session, next) {
	console.log("get msg:%j",msg);
  next(null, {code: 200, msg: 'game server is ok.'});
};




