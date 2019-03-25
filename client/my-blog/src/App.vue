<template>
  <div id="app">
    <Header></Header>
    <router-view></router-view>
  </div>
</template>

<script>
import Header from "./components/header.vue";
import HelloWorld from '@/components/HelloWorld.vue'
export default {
  name: "App",
  components: {
    Header
  }
};
</script>

<style lang='scss'>
html,
body,
#app {
  margin: 0;
  height: 100%;
  width: 100%;
  color: #3d3d3d;
  position: relative;
  overflow: hidden;
  Header{
    z-index: 2;
  }
}
</style>
