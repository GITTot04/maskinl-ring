<script setup lang="ts">
import { ref } from "vue";
const PakkeNummer = ref("14F16K-8583275832242758-DKF");

 function CopyParcelNumber() {
    navigator.clipboard.writeText(PakkeNummer.value);
    alert("Copied the text: " + PakkeNummer.value);
 }

</script>

<template>
  <div class="container"></div>
      <h1 class="No-select" style="font-size: 25px; padding-top: 10px;" >PAKKE INFO</h1>
      <div id="BarcodeIcon"></div>
      <p class="No-select" style="font-size: 25px; padding-top: 5px;">Pakkenummer</p>
      <div @click="CopyParcelNumber" class="PakkeNummer" >
        <p class="No-select">{{PakkeNummer}}</p>
        <div id="CopyIcon"></div>
      </div>
      <div class="wrapper">
        <div class="one">
          <h1>Afsender adresse</h1>
        </div>
        <div class="two">
          <h1>Modtager adresse</h1>
        </div>
        <div class="three">
          <h1>Hyldenummer</h1>
        </div>
        <div class="four">
          <h1>Status</h1>
        </div>
        <div class="five">
          <h1>Tilføjet d.</h1>
        </div>
        <div class="six">
          <h1>Forventet d.</h1>
        </div>
      </div>
    </template>

<style scoped>
.container {
  width: 100%;
}
.No-select {
  -webkit-user-select: none; /* Safari */        
  -moz-user-select: none; /* Firefox */
  -ms-user-select: none; /* IE10+/Edge */
  user-select: none; /* Standard */
}
#BarcodeIcon {
  width: 100%;
  height:85px;
  background-image: url(../assets/Icons/barcode.png);
  background-repeat: no-repeat;
  background-size: 85px;
  background-position: center 5px;
}
.PakkeNummer {
  display: flex;
  justify-content: center;
  align-items: center;
  text-align: center;
  width: 100%;
  transition: transform 0.5s ease-in-out;
}
.PakkeNummer:hover {
  display: flex;
  align-items: center;
  transform: scale(0.9);
}

.PakkeNummer #CopyIcon {
  width: 30px;
  height:30px;
  background-image: url(../assets/Icons/copy.png);
  background-repeat: no-repeat;
  background-size: contain;
  margin-left: 5px;
  margin-bottom: -5px;
}
.PakkeNummer p {
  padding-top: 5px;

  font-size: 20px;
  font-weight: bold;
}

/* Grid layout of the six columus with address and such information */
.wrapper {
  display: grid;
  grid-template-areas:
    "📧 🏠"
    "🛫 🛬"
    "📅 📆";
  gap: 10px;
  grid-auto-rows: minmax(100px, auto);
}
.one {
  grid-area: 📧;
}
.two {
  grid-area: 🏠;
}
.three {
  grid-area: 🛫;
}
.four {
  grid-area: 🛬;
}
.five {
  grid-area: 📅;
}
.six {
  grid-area: 📆;
}

</style>
