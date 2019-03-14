<template>
  <div class="login-main">
    <div class="site-body">
      <div class="login-body">
        <el-row>
          <el-col span='int(15)'>
            <span>小宝贝的姓名</span>
          </el-col>
          <el-col span=14>
            <el-input></el-input>
          </el-col>
        </el-row>
        <el-row>
          <el-col span=10>
            <span>小宝贝的Token</span>
          </el-col>
          <el-col span=14>
            <el-input></el-input>
          </el-col>
        </el-row>
      </div>
    </div>
  </div>
</template>

<script>
  export default {
    name: "Login",
    created: function () {
      console.log('hello~~');
    }

  }
</script>

<style lang="scss">
  .login-main {
    background-color: #dedbdb;
    height: calc(100%);
    display: flex;
    justify-content: center;
    .site-body {
      margin-top: 9%;
      background-color: #efefef;
      width: 45%;
      height: 50%;
      box-shadow: 10px 10px 5px #b4b4b4;
      display: flex;
      .login-body {
        display: flex;
        flex-direction: column;
        justify-content: center;
        align-items: center;
        .el-row {
          display: flex;
          margin-bottom: 2%;
          span {
            white-space: nowrap;
            overflow: hidden;
            display: flex;
            align-items: center;
            justify-content: flex-end;
            padding-right: 8%;
          }
        }
      }
    }
  }
</style>
