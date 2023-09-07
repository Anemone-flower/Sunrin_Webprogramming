const canvas = document.getElementById("game");
const ctx = canvas.getContext("2d");

let score;
let scoreText;
let highscore;
let highscoreText;
let dino;
let gravity;
let obstacles = [];
let gameSpeed;
let keys = {};

document.addEventListener("keydown", function (evt) {
  keys[evt.code] = true;
});
document.addEventListener("keyup", function (evt) {
  keys[evt.code] = false;
});

class Text {
  constructor(t, x, y, a, c, s) {
    this.t = t;
    this.x = x;
    this.y = y;
    this.a = a;
    this.c = c;
    this.s = s;
  }

  Draw() {
    ctx.beginPath();
    ctx.fillStyle = this.c;
    ctx.font = this.s + "px sans-serif";
    ctx.textAlign = this.a;
    ctx.fillText(this.t, this.x, this.y);
    ctx.closePath();
  }
}

class Dino {
  constructor(x, y, w, h, c) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.c = c;

    this.dy = 0;
    this.jumpForce = 15;
    this.originalHeight = h;
    this.grounded = false;
    this.jumpTimer = 0;
  }

  Draw() {
    var img = new Image();
    if ((keys["ShiftLeft"] || keys["KeyS"]) && this.grounded) {
      img.src = "dino_down.png";
      ctx.drawImage(img, this.x, this.y, this.w, this.h);
    } else {
      img.src = "dino_up.png";
      ctx.drawImage(img, this.x, this.y, this.w, this.h);
    }
  }

  Jump() {
    if (this.grounded && this.jumpTimer == 0) {
      this.jumpTimer = 1;
      this.dy = -this.jumpForce;
    } else if (this.jumpTimer > 0 && this.jumpTimer < 15);
    {
      this.jumpTimer++;
      this.dy = -this.jumpForce - this.jumpTimer / 50;
    }
  }

  Animate() {
    if (keys["Space"] || keys["KeyW"]) {
      if (this.grounded == true) this.Jump(); // 바닥에서만 점프
    } else {
      this.jumpTimer = 0;
    }

    if ((keys["ShiftLeft"] || keys["KeyS"]) && this.grounded) {
      this.y += this.h / 2;
      this.h = this.originalHeight / 2;
    } else {
      this.h = this.originalHeight;
    }

    this.y += this.dy;

    if (this.y + this.h < canvas.height) {
      this.dy += gravity;
      this.grounded = false;
    } else {
      this.dy = 0;
      this.grounded = true;
      this.y = canvas.height - this.h;
    }

    this.Draw();
  }
}

class Obstacle {
  constructor(x, y, w, h, c) {
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
    this.c = c;

    this.dx = -gameSpeed;
  }

  Update() {
    this.x += this.dx;
    this.Draw();
    this.dx = -gameSpeed;
  }

  Draw() {
    ctx.beginPath();
    ctx.fillStyle = this.c;
    ctx.fillRect(this.x, this.y, this.w, this.h);
    ctx.closePath();
  }
}

function SpawnObstacle() {
  let size = RandomIntInRange(20, 70);
  let type = RandomIntInRange(0, 1);
  let obstacle = new Obstacle(
    canvas.width + size,
    canvas.height - size,
    size,
    size,
    "#2484E4"
  );

  if (type == 1) {
    obstacle.y -= dino.originalHeight - 10;
  }
  obstacles.push(obstacle);
}

function RandomIntInRange(min, max) {
  return Math.round(Math.random() * (max - min) + min);
}

let initialSpawnTimer = 200;
let SpawnTimer = initialSpawnTimer;

function Update() {
  requestAnimationFrame(Update);
  ctx.clearRect(0, 0, canvas.witdth, canvas.height);
  dino.Animate();

  SpawnTimer--;
  if (SpawnTimer <= 0) {
    SpawnObstacle();
    console.log(obstacles);
    SpawnTimer = initialSpawnTimer - gameSpeed * 8;

    if (SpawnTimer < 60) {
      SpawnTimer = 60;
    }
  }
  for (let i = 0; i < obstacles.length; i++) {
    let o = obstacles[i];
    o.Update();
  }
  score++;
  scoreText.t = "Score : " + score;
  scoreText.Draw();
  gameSpeed += 0.003;
}

function Start() {
  canvas.witdth = window.innerWidth;
  canvas.height = window.innerHeight;

  ctx.font = "20px sans-serif";

  gameSpeed = 3;
  gravity = 1;

  score = 0;
  highscore = 0;

  dino = new Dino(25, canvas.height - 150, 50, 50, "pink");

  scoreText = new Text("Score : " + score, 25, 25, "left", "#212121", "20");

  requestAnimationFrame(Update);
}
Start();
