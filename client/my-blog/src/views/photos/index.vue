<template>
  <div class="photo-body">
    <div class="photo-container">
      <div class="title">{{title}}</div>
      <div class="content">
        <el-carousel :interval="5000" arrow="always">
          <el-carousel-item v-for="item in 6" :key="item">
            <h3>{{ item }}</h3>
          </el-carousel-item>
        </el-carousel>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  data: function() {
    return {
      title: "photo"
    };
  },
};
</script>
<style lang = 'scss'>
.photo-body {
  width: 100%;
  height: calc(100%-80px);
  min-height: 100%;
  background-color: rgb(250, 243, 231);
  position: relative;
  font-family: "Courier New", Courier, monospace;
  font-size: 1.4em;
  .photo-container {
    /* margin-top: 4%; */
    position: absolute;
    width: 100%;
    height: 50%;
    left: 50%;
    padding: 2%;
    background-color: rgba(204, 205, 209, 0.712);
    box-shadow: 2px 2px 2px gray;
    transform: translate(-50%, 0);
    .title {
      width: 100%;
      height: fit-content;
      text-align: center;
    }
    .content {
      position: relative;
      height: 100%;
      .el-carousel {
        position: absolute;
        top: 50%;
        left: 50%;
        transform: translate(-50%, -50%);
        width: 50%;
        margin: 0 auto;
        text-align: center;
      }
    }
  }
}
</style>

