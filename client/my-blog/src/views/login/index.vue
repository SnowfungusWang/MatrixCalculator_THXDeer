<template>
  <div class="login-main">
    <div class="site-body">
      <div class="login-body">
        <el-row>
          <el-col span="6">
            <span>姓名:</span>
          </el-col>
          <el-col span="16">
            <el-input></el-input>
          </el-col>
        </el-row>
        <el-row>
          <el-col span="6">
            <span>Token:</span>
          </el-col>
          <el-col span="16">
            <el-input></el-input>
          </el-col>
        </el-row>
        <el-row class="btn-group">
          <el-button>clear</el-button>
          <el-button>check</el-button>
        </el-row>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: "Login",
  created: function() {
    console.log("hello~~");
  }
};
</script>

<style lang="scss">
.login-main {
  background-color: #dedbdb;
  height: calc(100%);
  display: flex;
  justify-content: center;
  .site-body {
    margin-top: 9%;
    position: relative;
    background-color: #efefef;
    width: 45%;
    height: 50%;
    box-shadow: 0 1px 5px #928e8e;
    display: flex;
    .login-body {
      position: absolute;
      top: 50%;
      left: 50%;
      transform: translate(-50%, -50%);
      font-family: "Courier New", Courier, monospace;
      .el-row {
        margin-bottom: 5%;
        display: flex;
        align-items: center;
        justify-content: center;
        .el-col {
          text-align: right;
          span {
            flex: 1 0 auto;
            padding-right: 20%;
            white-space: nowrap;
            overflow: hidden;
          }
        }
        .el-button{
          width: 30%;
        }
      }
    }
  }
}
</style>
