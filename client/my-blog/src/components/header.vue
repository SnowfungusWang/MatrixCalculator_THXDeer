<template>
  <div class="header-body">
    <div class="header-icon"></div>
    <div class="header-fill"></div>
    <div class="header-navigation">
    </div>
  </div>
</template>
<script>
export default {
  name: "Header",
  data: function() {
    return {
      t: "a"
    };
  }
};
</script>

<style lang="scss">
.header-body {
  height: fit-content;
  max-height: 5%;
  width: 100%;
  background-color: aquamarine;
  display: flex;
  justify-content: space-between;
  div {
    padding: 1%;
    height: 100%;
    
  }
  .header-icon {
    flex: 1 0 auto;
    border: 1px salmon solid;
  }
  .header-fill {
    flex: 2 0 auto;
    border: 1px gold solid;
  }
  .header-navigation {
    flex: 2 0 auto;
    background-color: azure;
  }
}
</style>
